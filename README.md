# stack-01
括号匹配

题目：假设一个算术表达式中包含圆括号、方括号、和花括号三种类型的括号，编写一个算法来判别表达式中的括号是否配对，以字符“\0”作为算术表达式的结束符。

算法的基本思想：
扫描每个字符，遇到花、中、方的左括号进栈，遇到花、中、方的右括号时检查栈顶元素是否为对应的左括号，若是，退栈，否则配对失败。最后栈不为空也为错误。
