#include "rtweekend.h"

#include "aarect.h"
#include "box.h"
#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"
#include "bvh.h"
#include <iostream>


color ray_color(
    const ray& r,
    const color& background,
    const hittable& world,
    shared_ptr<hittable> lights,
    int depth
) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0,0,0);

    // If the ray hits nothing, return the background color.
    if (!world.hit(r, 0.001, infinity, rec))
        return background;

    scatter_record srec;
    color emitted = rec.mat_ptr->emitted(r, rec, rec.u, rec.v, rec.p);

    if (!rec.mat_ptr->scatter(r, rec, srec))
        return emitted;

    if (srec.is_specular) {
        return srec.attenuation
             * ray_color(srec.specular_ray, background, world, lights, depth-1);
    }

    auto light_ptr = make_shared<hittable_pdf>(lights, rec.p);
    mixture_pdf p(light_ptr, srec.pdf_ptr);
    ray scattered = ray(rec.p, p.generate(), r.time());
    auto pdf_val = p.value(scattered.direction());

    return emitted
         + srec.attenuation * rec.mat_ptr->scattering_pdf(r, rec, scattered)
                            * ray_color(scattered, background, world, lights, depth-1)
                            / pdf_val;
}


hittable_list cornell_box() {
    hittable_list objects;

    auto red   = make_shared<lambertian>(color(.65, .05, .05));
    auto white = make_shared<lambertian>(color(1, 1, 1));
    auto green = make_shared<lambertian>(color(.12, .45, .15));
    auto blue = make_shared<lambertian>(color(.12, .12, .60));
    auto purple = make_shared<lambertian>(color(1,.16,.83));
    auto light = make_shared<diffuse_light>(color(20, 20, 20));
    auto glass = make_shared<dielectric>(1.5);
    auto black = make_shared<dielectric>(1.5);

    objects.add(make_shared<yz_rect>(0, 555, 0, 555, 555, blue)); //parede esquerda
    objects.add(make_shared<yz_rect>(0, 555, 0, 555, 0, purple)); //parece direita
    objects.add(make_shared<flip_face>(make_shared<xz_rect>(213, 343, 227, 332, 554, light))); //lampada
    objects.add(make_shared<xz_rect>(0, 555, 0, 555, 555, glass)); //teto
    objects.add(make_shared<xz_rect>(0, 555, 0, 555, 0, glass)); //piso
    objects.add(make_shared<xy_rect>(0, 555, 0, 555, 555, white)); //parede fundo

    shared_ptr<material> aluminum = make_shared<metal>(color(0.8, 0.85, 0.88), 0.0);
    shared_ptr<material> blue_metal = make_shared<metal>(color(.12, .12, .60), 0.0);

    shared_ptr<hittable> box1 = make_shared<box>(point3(0,0,0), point3(165,330,165), aluminum);
    box1 = make_shared<rotate_y>(box1, 35);
    box1 = make_shared<translate>(box1, vec3(265,0,295));
    objects.add(box1); //retangulo

    objects.add(make_shared<sphere>(point3(190,90,190), 90 , glass)); 
    objects.add(make_shared<sphere>(point3(350,400,150), 45, blue_metal));
    objects.add(make_shared<sphere>(point3(450,90,100), 45, light));

    hittable_list boxes2;
    int ns = 1000;
    for (int j = 0; j < ns; j++) {
        boxes2.add(make_shared<sphere>(point3::random(0,165), 10, white));
    }

    objects.add(make_shared<translate>(
        make_shared<rotate_y>(
            make_shared<bvh_node>(boxes2, 0.0, 1.0), 15),
            vec3(50,270,395)
        )
    );

    return objects;
}


int main() {
    // Image

    const auto aspect_ratio = 1.0 / 1.0;
    const int image_width = 600;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 1000;
    const int max_depth = 50;

    // World

    auto lights = make_shared<hittable_list>();
    lights->add(make_shared<xz_rect>(213, 343, 227, 332, 554, shared_ptr<material>()));
    lights->add(make_shared<sphere>(point3(190, 90, 190), 90, shared_ptr<material>()));

    auto world = cornell_box();

    color background(0,0,0);

    // Camera

    // point3 lookfrom(278, 278, -800);//frente
    // point3 lookfrom(278, 0, -800);//baixo
    // point3 lookfrom(0, 278, -800); //direita
    // point3 lookfrom(555, 278, -800); //esquerda
    point3 lookfrom(278, 555, -800); //cima

    point3 lookat(278, 278, 0);
    vec3 vup(0, 1, 0);
    auto dist_to_focus = 10.0;
    auto aperture = 0.0;
    auto vfov = 40.0;
    auto time0 = 0.0;
    auto time1 = 1.0;

    camera cam(lookfrom, lookat, vup, vfov, aspect_ratio, aperture, dist_to_focus, time0, time1);

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0,0,0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width-1);
                auto v = (j + random_double()) / (image_height-1);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, background, world, lights, max_depth);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}