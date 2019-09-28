# ft_printf - 42/Codam
## Recoding printf in C from scratch

### Bonus functionality
#### 1. Wildcard
```
ft_printf("%*d", width, 1039)
```
The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. 
#### 2. Binary
```
ft_printf("%b", 255)
```
Converts unsigned int to binary. 

Flags accepted:
- Width
- Left-justify
- Fill width with zero's
#### 3. Integer array visualizer
```
ft_printf("%a", array, columns, rows)
```
Prints out 1 or more integer arrays. Needs length of every line (columns) and amount of lines (rows) following the argument that has to be formatted.

Flags accepted:
- Width
- Left-justify
- Fill width with zero's
#### 4. Character array visualizer
Prints out 1 or more character arrays. Needs length of every line (columns) and amount of lines (rows) following the argument that has to be formatted.

Flags accepted:
- Width
- Left-justify
- Fill width with zero's
#### 5. Emoji's
###### Use %s and emoji identifier
#### Emoji identifiers
#### \_JOY_ :joy:
#### \_EGGPLANT_ :eggplant:
#### \_AVOCADO_ :avocado:
