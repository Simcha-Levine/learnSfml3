project('learnSfml3', 'cpp', version : '0.1', 
  default_options : ['warning_level=3', 'cpp_std=c++20'])

sfml = [dependency('sfml-graphics'), dependency('sfml-window'), dependency('sfml-system')]
box2d = dependency('box2d')

src = ['main.cpp', 'Ground.cpp', 'Axis.cpp', 'Poly.cpp', 'ContactListener.cpp']

exe = executable('hellomeson', src, install : true, dependencies : [sfml, box2d])

test('basic', exe)