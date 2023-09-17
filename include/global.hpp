#include "main.h"
#include "pros/motors.hpp"
extern std::string alliance;
extern pros::Motor leftMtr;
extern pros::Motor rightMtr;
extern pros::Motor leftMtr1;
extern pros::Motor rightMtr1;
extern pros::Motor clawMtr;
extern pros::Motor armMtr;
extern pros::Motor tailMtr;
inline pros::MotorGroup left ({leftMtr,leftMtr1});
inline pros::MotorGroup right ({rightMtr,rightMtr1});


// ---------------- CONTROLLER ---------------- //
inline pros::Controller master(pros::E_CONTROLLER_MASTER);


// ---------------- SENSORS ---------------- //
inline pros::Rotation rot (99);
