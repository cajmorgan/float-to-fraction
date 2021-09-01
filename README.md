A simple yet effective library to convert a float 

```
3.6
```
To numerator/denominator
```
18/5
```
Written in C and exported to Node as a module.


```
npm install float-to-fraction 
```

In .js
```
const floatToFraction = require('float-to-fraction');

const float = 3.6;
const returnedArr = floatToFraction(float); //Returns [18, 5];
```

Note: the algorithm tries to find the smallest nominator/denominator relationship with the float applied. Most of the time the algorithm returns the correct fraction but it is not 100% accurate on every application, which depends on different factors like rational/irrational numbers and number of decimals. 

The algorithm is based off: https://en.wikipedia.org/wiki/Continued_fraction
