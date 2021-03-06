/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature BLUEBALL = vex::vision::signature (1, -3369, -1661, -2515, 3909, 11915, 7912, 2.5, 0);
vex::vision::signature REDBALL = vex::vision::signature (2, 7795, 8937, 8366, 163, 1403, 783, 2.5, 0);
vex::vision::signature SIG_3 = vex::vision::signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision VisionSensor = vex::vision (vex::PORT1, 50, BLUEBALL, REDBALL, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/