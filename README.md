# ofxTraerPhysics

A C++ port of the Processing traer physics library, designed specifically for openframeworks.


## Requirements
None for openFrameworks!

This addon has been tested with openFrameworks v0.9.1

If you want to port this library to any other flavor of C++, it's easily extensible -- the only reliance on openframeworks in the use of the `ofVec3f` class for vector arithmetic.

## Usage
The entry point is `ofxParticleSystem`; create an instance of it via `ofxParticleSystem::make()` to get started.

## Examples

## Contributing

This project uses the [Git Flow](http://nvie.com/posts/a-successful-git-branching-model/) paradigm.  Before contributing, please make your own feature branch with your changes.

## More Information
Jeffrey Bernstein's Traer Physics library that inspired this addon can be found (http://murderandcreate.com/physics/)[here].
