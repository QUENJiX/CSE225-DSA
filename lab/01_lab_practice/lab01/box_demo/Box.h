#ifndef BOX_H
#define BOX_H

class Box {
   private:
    double height;
    double width;
    double depth;

   public:
    Box(double h, double w, double d);
    void volume() const;
};
#endif
