# MPC Controller Project submission.

This repository is forked from [Udacity CarND-MPC-Project](git@github.com:udacity/CarND-MPC-Project.git).
Please refer to [Original README](./README-org.md) for set-up, etc.

## Rubric Points

### The Model

#### State

6 dimension vector.

- x[0] : Position of the car.
- x[1] : Position of the car.
- x[2] : Angle of the car.
- x[3] : Speed of the car.
- x[4] : cte: Distance from the reference trajectory.
- x[5] : epsi: Angle difference between the reference trajectory and actual direction.

#### Actuator

- Steering Angle: Steering Angle in radian. Value range is [-1, 1].
- Throttle: Acceleration. Value range is [-1, 1].

#### Cost function

- Cost function to be minimized:

```
10 * cte(t)^2 +
10 * epsi(t)^2 +
(v(t) - 40)^2 +
steering_angle(t)^2 +
throttle(t)^2 +
500 * (steering_angle(t+1)-steering_angle(t+1))^2 +
(throttle(t+1)-throttle(t)^2
```

### Timestep Length and Elapsed Duration (N & dt)

Choose N=10 and dt=0.2

#### N
When N=20, it takes around 0.6-0.8 sec to solve the equation while it takes around 0.2 sec if N=10.
Although MPC can deal with the latency, it's better choose lighter calculation if possible.


#### dt under N=10

- dt=0.1 : Predicted line is too short and makes the drive bit bumpy.

- dt=0.5 : Predicted line is bit longer than the reference. Although the car
can go around the course, prediction was bit unstable.

There's some possible combination such as N=5, dt=0.5 go around the course
with reasonable bumpiness.
However larger dt might cause problems if there's steep curve or target speed
is higher.

### Model Predictive Control with Latency

To deal with latency, predict the car position/angle/speed after 100ms and
use it as initial state.

