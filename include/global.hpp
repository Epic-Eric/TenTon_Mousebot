#include "main.h"
#include "pros/motors.hpp"
extern std::string alliance;
extern pros::Motor leftMtr;
extern pros::Motor rightMtr;
extern pros::Motor clawMtr;
extern pros::Motor armMtr;
extern pros::Motor tailMtr;
inline pros::MotorGroup left ({leftMtr});
inline pros::MotorGroup right ({rightMtr});


// ---------------- CONTROLLER ---------------- //
inline pros::Controller master(pros::E_CONTROLLER_MASTER);


// ---------------- SENSORS ---------------- //
inline pros::Rotation rot (99);
