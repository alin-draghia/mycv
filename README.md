# mycv

Some simple object detection library I've written long time ago

The main thing about the detector is that it trains realy fast(suitable for online learning), 
uses a single positive sample and gererates random transformations also it does 
negative mining from image patches that suround the positive sample.

As classifier I've implemented a variant of random forrest with bagging.

Also, I've experimented with static polimorfism via template metaprogramming


![features](/docs/mycv_features.jpg?raw=true "Learned Features")

![detection](/docs/mycv_detection.jpg?raw=true "Detection Result")
