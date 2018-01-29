# playhead2OSC
## description
playhead2OSC is an audio plugin written with juce. It sends information about the playhead via OSC. By now it captures the following features:

* bpm
* time signature
* time in seconds
* is playing
* is recording
* is looping

## usage
### installation
Download the plugin from the releases tab and copy the audio uni (playhead2OSC.component) to your mac's audio unit directory (/Library/Audio/Plug-Ins/Components).

### DAW
Make sure your DAW finds the plugin. Drag it then to one of your tracks. it makes sense to drag it to the master effects chain. Then set the remote hosts ip and port. By default it sends to localhost:9001.
