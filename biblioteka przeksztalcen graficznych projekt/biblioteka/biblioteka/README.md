
# GRAPHIC TRANSFORMATIONS LIBRARY

In this project I implemented several transformations on 3D objects loaded from .obj files.


Obj class loads points and vertexes from 3D object

Then they can be changed by transformations as:

-translations

-rotations

-scaling

The transformations can be combined

for example we've got:

Transformation by some vector called 'T', Scaling 'S' and rotation 'R'

We can do:

T + S + R

which gives us a resultant transformation that changes the points of 3d object


After all the new shape of an object is again saved in .obj file.


For all calculations the stack of matrix is used.
We can easily get back to previous form of an object by replacing transformations, because they all inherit from one base class.
