#include <iostream>
using namespace std;

class BasicPhysics
{
private:
  float Gravity = 9.8;

public:
  BasicPhysics(/* args */);
  ~BasicPhysics();
};

BasicPhysics::BasicPhysics(/* args */)
{
}

BasicPhysics::~BasicPhysics()
{
}

class object
{
  float mass;
  float x_coordinate;
  float y_coordinate;
  float z_coordinate;

public:
  float get_x_coordinate() { return x_coordinate; }
  float get_y_coordinate() { return y_coordinate; }
  float get_z_coordinate() { return z_coordinate; }
  float get_mass() { return mass; }

  void set_x_coordinate(float Setter) { x_coordinate = Setter; }
  void set_y_coordinate(float Setter) { y_coordinate = Setter; }
  void set_z_coordinate(float Setter) { z_coordinate = Setter; }
  void set_mass(float Setter) { mass = Setter; }

  object( float m,float x=0, float y=0, float z=0)
  {
    mass = m;
    x_coordinate = x;
    y_coordinate = y;
    z_coordinate = z;
  }

  void print_coordinates(){
    cout<<"X coordinate  ::  "<<x_coordinate<<endl;
    cout<<"Y coordinate  ::  "<<y_coordinate<<endl;
    cout<<"Z coordinate  ::  "<<z_coordinate<<endl;
  }
};

class force
{
  float x_force;
  float y_force;
  float z_force;

public:
  float get_x_force() { return x_force; }
  float get_y_force() { return y_force; }
  float get_z_force() { return z_force; }

  force(float x = 0, float y = 0, float z = 0)
  {
    x_force = x;
    y_force = y;
    z_force = z;
  }
};

void final_coordinate_calculator(object *obj, force *f, int time)
{
  // force = mass * acceleration
  float acceleration_x = f->get_x_force() / obj->get_mass();
  float acceleration_y = f->get_y_force() / obj->get_mass();
  float acceleration_z = f->get_z_force() / obj->get_mass();

  obj->set_x_coordinate((obj->get_x_coordinate() + acceleration_x * time));
  obj->set_y_coordinate((obj->get_y_coordinate() + acceleration_x * time));
  obj->set_z_coordinate((obj->get_z_coordinate() + acceleration_x * time));
}

int main()
{

  force f(10, 10, 10);
  object obj(10);
  obj.print_coordinates();

  final_coordinate_calculator(&obj,&f,10);
  obj.print_coordinates();


  return 0;
}