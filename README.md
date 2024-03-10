# cv KCF tracker

this is simple implementation of tracker writen by chat_GPT:)

to run the code:

- git clone https://github.com/Dmitriy-Belitskiy/cv_boost_tracker
- docker build -t cv_tracker -f Dockerfile . # compilation take over 20 minutes (depends on hardware)
- xhost +local:   # before launching the container, allow display access from local users
- sudo docker run -it --rm --privileged -e DISPLAY=$DISPLAY -v /tmp/.X11-unix/:/tmp/.X11-unix:ro cv_tracker

