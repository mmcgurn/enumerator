# enumerator
a library/executable that create a file from a template for every enumeration 

This library/executable allows generating an enumerations of inputs.
The minimum required options is a path to an input file:

```bash
    ./enumerator --input=path/to/input.yaml
```

## Template String Example
In this example a string is provided in the template file directly.  Arguments in the template are replaced with specified enumerations if they are in the template as {{varName}}.

### templateStringExample.yaml
```yaml
---
name: exampleFileGen.
enumerations:
  - !enumerator::enumerations::List
    name: mu
    values: [ .1, .2, .3 ]
  - !enumerator::enumerations::List
    name: density
    values: [ 1.1, 1.2 ]
generator:
  !enumerator::generators::TemplateGenerator
  template: |
    #!/bin/bash
    echo "Hello World {{mu}} and {{density}}
  extension: .sh
  outputDirectory: outputs
reporters:
  - !enumerator::reporters::StreamReporter
```


## Template File Example
In this example uses a template file for the basis.

### templateFileExample.yaml
```yaml
---
name: exampleFileGen.
enumerations:
  - !enumerator::enumerations::List
    name: mu
    values: [ .1, .2, .3 ]
  - !enumerator::enumerations::List
    name: density
    values: [ 1.1, 1.2 ]
generator:
  !enumerator::generators::FileTemplateGenerator
  path: template.sh
reporters:
  - !enumerator::reporters::StreamReporter
```

### template.sh
```shell
#!/bin/bash

echo "Hello World {{mu}} and {{density}}
```

## Building Enumerator
The enumerator project can be built using CMake.  Examples and additional details are provided by [CMake](https://cmake.org/runningcmake/).  

