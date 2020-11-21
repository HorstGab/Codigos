#include <iostream>

#include "rtweekend.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"




color ray_color(const ray& r, const hittable& world, int depth) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0) return color(0,0,0);

    if (world.hit(r, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth-1);
        return color(0,0,0);
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}


int main() {

    //Image
    const auto aspect_ratio = 3.0 / 2.0;
    const int image_width = 1200;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 500;
    const int max_depth = 50;

    // World
    hittable_list world;

    auto material_behind = make_shared<lambertian>(color(0.9, 0.5, 0.0));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(2.0);
    auto material_right  = make_shared<metal>(color(0.8, 0.0, 0.5), 0.0);
    auto material_top  = make_shared<metal>(color(0.0, 0.0, 0.0), 0.0);
    auto material_up  = make_shared<metal>(color(0.0, 0.5, 0.0), 1.0);
    auto material_down  = make_shared<metal>(color(0.5, 0.5, 0.5), 0.0);

    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center)); 
    world.add(make_shared<sphere>(point3( 2.0,    0.0, -1.0),   1, material_right));
    world.add(make_shared<sphere>(point3(0.0,    0.0, 1.0),   1, material_top));
    world.add(make_shared<sphere>(point3(-1.5,    0.0, -1.0), 0.5, material_left));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -2.5),   0.75, material_behind));
    world.add(make_shared<sphere>(point3( 0.0,    1.0, -1.0),   0.5, material_up));
    world.add(make_shared<sphere>(point3( 0.0,    -1.5, -1.0),   1, material_down));
   

    //Camera
//  camera cam(point3(-2,2,2), point3(0,0,-1), vec3(0,1,0), 90, aspect_ratio);
//  camera cam(point3(-2,2,-2), point3(0,0,-1), vec3(0,1,0), 90, aspect_ratio);
//  camera cam(point3(2,2,-2), point3(0,0,-1), vec3(0,1,0), 90, aspect_ratio);
//  camera cam(point3(2,2,2), point3(0,0,-1), vec3(0,1,0), 90, aspect_ratio);
    camera cam(point3(0,5,0), point3(0,0,-1), vec3(0,1,0), 90, aspect_ratio);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width-1);
                auto v = (j + random_double()) / (image_height-1);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world, max_depth);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << "\nDone.\n";    
}