This document is used for writing down all ideas during the brainstorming
process for how the video-flow-control application should be designed and built.

The application should be modular so that new components can be 
seamlessly added without the need to add code into the other components
to accommodated the new component. For example, we should easily be able
to add new sources of video into the system without the other components
needing to rely on exactly where that video is coming from. This implies
that we should abstract what a video frame is into our own data structure
that we then make other video sources conform to. It shouldn't matter if
the video is coming from a file, camera, etc. Some basic modules/systems
that will need to be created are a video source manager, video processing
module(s), streaming system, display/windowing system, UI system, video
saving module, metadata manager, the main application component that 
coordinates the flow through the system. 

The video source manager will be responsible for handling the video data
from external sources. It should provide an interface to get video frames
in a standardized way. It should implement different modules for handling 
different types of video sources such as files and cameras. We need to 
think about what this system will do for different types of video 
sources. For something like a camera should there be a callback that it
is set up to to send received video frames to as it will be a continuos 
stream of video. But for something like a file would this make since? 
Question: How should we standardize this? Should there be an extra level
of abstraction for these different sources?

The video processing module(s) will simply handle image processing
algorithms that either add extra information to the video frame or alter
the image in some way. These are things like object detection and image
filters. The user should be able to dynamically add and remove these 
different processes from a specific video source. The main application 
component may want to send all images through these modules before doing 
anything else with them.

The streaming system is just a system used to send the final output video
to services such as YouTube, Twitch, etc. This is a low priority system 
currently.

The display/windowing system is the system that provides a means to view
the final output video locally. It will use things like GLFW and OpenGL.
It should support the creation of multiple windows if there are multiple 
video sources in use. We may delegate that function to the UI module and 
have each window be rendered to an imgui window.

The UI system deals with all the UI. We will us imgui for easy and clean 
interfaces. The application should be able to be run in a windowless mode
but this UI system can be used to set up certain things will user defined
preferences and then save them to a file somewhere. For example, we may 
need the user to login to their YouTube account in order to stream the 
output and this could be setup using the UI system but it would just store
that information in an encrypted file.

The video saving module is used to save the output in different formats. 
This is also a low priority system currently.

The metadata manager handles video metadata, such as timestamps, frame rates, resolution, and any other relevant information that may be needed. 

The most critical components are the video source manager, display/
windowing system, and the main application component. Below will be 
the design and considerations for each of these components.

# Display/Windowing System

There will be one main window, this is the window created by GLFW. Inside 
that window there will be multiple different UI components. Some of these
include imgui windows that display a video feed. The main window will 
create events. These are things such as keyboard events, mouse events, 
etc. It will pass these on to the event manager which should handle the
events appropriately.

# Video Source Manager



# Main Application