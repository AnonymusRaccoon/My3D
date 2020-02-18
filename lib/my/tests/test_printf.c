/*
** EPITECH PROJECT, 2019
** Tests
** File description:
** test_disp_stdarg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(disp, first, .init = cr_redirect_stdout)
{
    my_printf("Insane %s, %c, %d, %s\n", "Yes", '8', 15, "Nope");
    cr_assert_stdout_eq_str("Insane Yes, 8, 15, Nope\n");
}

Test(disp, faketag, .init = cr_redirect_stdout)
{
    my_printf("Insane %Y, %c, %d, %s\n", '8', 15, "Nope");
    cr_assert_stdout_eq_str("Insane %Y, 8, 15, Nope\n");
}

Test(disp, str, .init = cr_redirect_stdout)
{
    my_printf("Insane %s\n", "156615");
    cr_assert_stdout_eq_str("Insane 156615\n");
}

Test(disp, uints, .init = cr_redirect_stdout)
{
    my_printf("Insane %u\n", 156615);
    cr_assert_stdout_eq_str("Insane 156615\n");
}

Test(disp, characters, .init = cr_redirect_stdout)
{
    my_printf("Insane %c\n", '^');
    cr_assert_stdout_eq_str("Insane ^\n");
}

Test(disp, ints, .init = cr_redirect_stdout)
{
    my_printf("Insane %d, %i\n", 15, -15);
    cr_assert_stdout_eq_str("Insane 15, -15\n");
}

Test(disp, ptr, .init = cr_redirect_stdout)
{
    int ptr = 15;
    char *str = malloc(sizeof(char) * 25);

    my_printf("Insane %p\n", &ptr);
    sprintf(str, "Insane %p\n", &ptr);
    cr_assert_stdout_eq_str(str);
}

Test(disp, nonprintable, .init = cr_redirect_stdout)
{
    my_printf("Insane %S\n", "\aYes\a");
    cr_assert_stdout_eq_str("Insane \\007Yes\\007\n");
}

Test(disp, binary, .init = cr_redirect_stdout)
{
    my_printf("%b\n", 153152);
    cr_assert_stdout_eq_str("100101011001000000\n");
}

Test(disp, octal, .init = cr_redirect_stdout)
{
    my_printf("%o\n", 153152);
    cr_assert_stdout_eq_str("453100\n");
}

Test(disp, hexa, .init = cr_redirect_stdout)
{
    my_printf("%x\n", 1561356523);
    cr_assert_stdout_eq_str("5d1068eb\n");
}

Test(disp, bighexa, .init = cr_redirect_stdout)
{
    my_printf("%X\n", 1561356523);
    cr_assert_stdout_eq_str("5D1068EB\n");
}

Test(disp, uintneg, .init = cr_redirect_stdout)
{
    my_printf("%u\n", -500);
    cr_assert_stdout_eq_str("4294966796\n");
}

Test(disp, noformat, .init = cr_redirect_stdout)
{
    my_printf("%%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(disp, floats, .init = cr_redirect_stdout)
{
    my_printf("%f\n", 13.684);
    cr_assert_stdout_eq_str("13.684\n");
}

Test(disp, morefloat, .init = cr_redirect_stdout)
{
    my_printf("%f\n", 18.138613);
    cr_assert_stdout_eq_str("18.138613\n");
}

Test(my_printf, mouliS, .init = cr_redirect_stdout)
{
    my_printf("%S", "mouline\atte\n");
    cr_assert_stdout_eq_str("mouline\\007tte\\012");
}

Test(my_printf, simplePtr, .init = cr_redirect_stdout)
{
    my_printf("%p", 3456789);
    cr_assert_stdout_eq_str("0x34bf15");
}

Test(my_printf, intLength, .init = cr_redirect_stdout)
{
    my_printf("%05i", 15);
    cr_assert_stdout_eq_str("00015");
}

Test(my_printf, intPlusSize, .init = cr_redirect_stdout)
{
    my_printf("%0+5i", 15);
    cr_assert_stdout_eq_str("+0015");
}

Test(my_printf, intLengthSpace, .init = cr_redirect_stdout)
{
    my_printf("% 05i", 15);
    cr_assert_stdout_eq_str(" 0015");
}

Test(my_printf, intLengthSpacePlus, .init = cr_redirect_stdout)
{
    my_printf("% 0+5i", -15);
    cr_assert_stdout_eq_str("-0015");
}

Test(my_printf, xLength, .init = cr_redirect_stdout)
{
    my_printf("%05X", 15);
    cr_assert_stdout_eq_str("0000F");
}

Test(my_printf, xPlusSize, .init = cr_redirect_stdout)
{
    my_printf("%0+5X", 15);
    cr_assert_stdout_eq_str("0000F");
}

Test(my_printf, xLengthSpace, .init = cr_redirect_stdout)
{
    my_printf("%#X", -15);
    cr_assert_stdout_eq_str("0XFFFFFFF1");
}

Test(my_printf, xLengthSpacePlus, .init = cr_redirect_stdout)
{
    my_printf("%# +X", -15);
    cr_assert_stdout_eq_str("0XFFFFFFF1");
}

Test(my_printf, stringWithMax, .init = cr_redirect_stdout)
{
    my_printf("%# +03s", "ABCDEFG");
    cr_assert_stdout_eq_str("ABC");
}