# ofxTraerPhysics

A C++ port of the Processing traer physics library, designed specifically for openframeworks.  This addon focuses on ease of use over performance; you'll find that it's not nearly as fast as a lighter weight system might be.  However, the hope is that it will serve as a useful addon for beginners or for people who just need to draft ideas quickly.


## Requirements
None for openFrameworks!

This addon has been tested with openFrameworks v0.9.1

If you want to port this library to any other flavor of C++, it's easily extensible -- the only reliance on openframeworks in the use of the `ofVec3f` class for vector arithmetic.

## Usage
This library uses the `ofxTraerPhysics` namespace to prevent namespace collisions with common class names like `ofxParticle` and `ofxForce`.  Hopefully this allows you to easily use it with other libraries!  If you get tired of typing out `ofxTraerPhysics::` before every class, feel free to use `using namespace ofxTraerPhysics` in your *implementation* files.

The entry point is `ofxParticleSystem`; create an instance of it via `ofxParticleSystem::make()` to get started.

## Examples

## Contributing

This project uses the [Git Flow](http://nvie.com/posts/a-successful-git-branching-model/) paradigm.  Before contributing, please make your own feature branch with your changes.

## More Information
Jeffrey Bernstein's Traer Physics library that inspired this addon can be found [here](http://murderandcreate.com/physics).
