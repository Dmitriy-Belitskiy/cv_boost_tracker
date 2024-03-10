# cv_boost_tracker, actualy KFC tracker




this is simple emplementation of tracler writen by chat_GPT:)

to run the code:

- git clone https://github.com/Dmitriy-Belitskiy/cv_boost_tracker

- docker build -t cv_tracker -f Dockerfile .

# compilation take over 20 minutes (depends from hardware)

# before launching the container, allow display access from local users
- xhost +local:   # this should be entered in the host terminal!


- sudo docker run -it --rm --privileged -e DISPLAY=$DISPLAY -v /tmp/.X11-unix/:/tmp/.X11-unix:ro my_cv

