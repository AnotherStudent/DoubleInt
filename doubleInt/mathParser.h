#ifndef MATH_PARSER
#define MATH_PARSER

double expression(char *exp);
double function_x(char *exp, double x_val);
double function_xy(char *exp, double x_val, double y_val);
int is_syntax_error(void);

#endif
