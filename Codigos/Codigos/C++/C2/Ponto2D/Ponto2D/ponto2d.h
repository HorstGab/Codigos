#ifndef PONTO2D_H
#define PONTO2D_H


class ponto2d{
protected:
    double x;
    double y;
public:
    ponto2d();
    ponto2d(double x, double y);
    ponto2d (ponto2d *p);

    double getx();
    double gety();

    void setx( double x);
    void sety( double y);

    void move();
    void move(double x, double y);
    void move(ponto2d *p);

    bool equals(ponto2d *p);
    double distance (ponto2d *p);

    ponto2d *clone;

    ~ponto2d();
};

#endif // PONTO2D_H
