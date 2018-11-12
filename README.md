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

## License
This project is released under MIT license, please note that dependencies might be released differently.

Copyright (c) 2018 Thomas Geissl

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
