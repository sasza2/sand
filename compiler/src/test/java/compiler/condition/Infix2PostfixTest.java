package compiler.condition;

import compiler.Code;
import compiler.Script;
import compiler.condition.element.Element;
import compiler.condition.transform.before.TransformException;
import compiler.exception.CompilerException;
import java.util.List;
import java.util.stream.Collectors;
import static org.junit.Assert.assertEquals;
import org.junit.Test;

/**
 *
 * @author sasza
 */
public class Infix2PostfixTest {

    @Test
    public void test1(){
        test("12 + a * (b * c + d / e)", "12 a b c * d e / + * +");
    }

    @Test
    public void test2(){
        test("(a+(b*c))", "a b c * +");
    }

    @Test
    public void test3(){
        test("((a+b)*(z+x))", "a b + z x + *");
    }

    @Test
    public void test4(){
        test("((a+t)*((b+(a+c))^(c+d)))", "a t + b a c + + c d + ^ *");
    }

    @Test
    public void test5(){
        test("(2+3)*5", "2 3 + 5 *");
    }

    @Test
    public void test6(){
        test("((2+7)/3+(14-3)*4)/2", "2 7 + 3 / 14 3 - 4 * + 2 /");
    }

    @Test
    public void test7(){
        test("!a + !b", "a ! b ! +");
    }

    @Test
    public void test8(){
        test("fun(x, 2, 4)", "x 2 4 fun:3");
    }

    @Test
    public void test9(){
        test("fun()", "fun:0");
    }

    @Test
    public void test10(){
        test("a(b)", "b a:1");
    }

    @Test
    public void test11(){
        test("f(x,y)", "x y f:2");
    }

    @Test
    public void test12(){
        test("f1(a,x,f2(b))", "a x b f2:1 f1:3");
    }

    @Test
    public void test13(){
        test("fun_y(a) * fun_x(b, c)", "a fun_y:1 b c fun_x:2 *");
    }

    @Test
    public void test14(){
        test("x(a * b)", "a b * x:1");
    }

    @Test
    public void test15(){
        test("a(ax * bx, cx * dx) ^ 5", "ax bx * cx dx * a:2 5 ^");
    }

    @Test
    public void test16(){
        test("fun(a * b(4), x(y(6, 4), 3)) + abc * 5 ^ 2", "a 4 b:1 * 6 4 y:2 3 x:2 fun:2 abc 5 2 ^ * +");
    }

    @Test
    public void test17(){
        test("a(1, b(2, c((3), 4)))", "1 2 3 4 c:2 b:2 a:2");
    }

    @Test
    public void test18(){
        test("x * z * a(3 ^ 5)", "x z * 3 5 ^ a:1 *");
    }

    @Test
    public void test19(){
        test("a[x] + 3", "a x ] 3 +");
    }

    @Test
    public void test20(){
        test("b[a[w ^ 3] + c[d]] * 18", "b a w 3 ^ ] c d ] + ] 18 *");
    }

    @Test
    public void test21(){
        test("x.y", "x y ]");
    }

    @Test
    public void test22(){
        test("x.c.d.a * 5", "x c ] d ] a ] 5 *");
    }

    @Test
    public void test23(){
        test("this.name + surname", "this name ] surname +");
    }

    @Test
    public void test24(){
        test("this.user[name]", "this user ] name ]");
        test("this.user.name", "this user ] name ]");
        test("this.user[name + surname]", "this user ] name surname + ]");
        test("this.str1.val()", "this str1 ] val ] ():0");
        test("this[x](a)", "this x ] a ():1");
        test("a[p](x, y * z[2])", "a p ] x y z 2 ] * ():2");
        test("this.test.test2(33)", "this test ] test2 ] 33 ():1");
        test("this.a[3](4) ^ this.b.x(5, 6 + g())", "this a ] 3 ] 4 ():1 this b ] x ] 5 6 g:0 + ():2 ^");
        test("a ^ b.x.y[3]", "a b x ] y ] 3 ] ^");
        test("a(z) ^ b.x.y[3](z)", "z a:1 b x ] y ] 3 ] z ():1 ^");
        test("this[str].reverse()", "this str ] reverse ] ():0");
        test("x == 3", "x 3 ==");
        test("x * 2 == y * 4", "x 2 * y 4 * ==");
        test("x || y == 2", "x || y 2 ==");
        test("x && y == 2", "x && y 2 ==");
        test("x && y == 2 && c ^ (3 * a)", "x && y 2 == && c 3 a * ^");
        test("a + 3 == fun(x + 10) + 1", "a 3 + x 10 + fun:1 1 + ==");
        test("a + 3 == fun(x && 3) && x == 2", "a 3 + x && 3 fun:1 == && x 2 ==");
        test("xyz(a && (z == 3 && p == 2))", "a && z 3 == && p 2 == xyz:1");
        test("xyz(a && (z == 3 && p == 2)) && c == 1", "a && z 3 == && p 2 == xyz:1 && c 1 ==");
        test("a == 2 && b == 3", "a 2 == && b 3 ==");
        test("a[x && y]", "a x && y ]");
        test("a == b && c", "a b == && c");
        test("a == (b && c)", "a b && c ==");
        test("a == 1 && (b == 2 && c == 3)", "a 1 == && b 2 == && c 3 ==");
        test("x || y && z", "x || y && z");
        test("-3", "-3");
        test("abc(-2 + 8)", "-2 8 + abc:1");
        test("(x)abc", "abc (x)");
        test("new user", "user new");
        test("new User()", "User:0:new");
    }

    @Test
    public void test25(){
        test("new User(a).test(b)", "a User:1:new test ] b ():1");
        test("3 + new Math(x).sum(5, 8) * 4", "3 x Math:1:new sum ] 5 8 ():2 4 * +");
        test("3 + new Math(x * (y + 2) + 3).sum(5, 8) * 4", "3 x y 2 + * 3 + Math:1:new sum ] 5 8 ():2 4 * +");
        test("x.toString() + y.reverse().toString()", "x toString ] ():0 y reverse ] ():0 toString ] ():0 +");
        test("new a[x + y](c ^ 2)", "a x y + ] c 2 ^ new[]:1");
        test("new a[x + y(4 - p) ^ 2](c ^ 2)", "a x 4 p - y:1 2 ^ + ] c 2 ^ new[]:1");
        test("a == false", "a false ==");
        test("a || (((b && c == 1 && x == 2) || a > 0) && c == 2)", "a || b && c 1 == && x 2 == || a 0 > && c 2 ==");
        test("(((b && c == 1 && x == 2) || a > 0) && c == 2) || a", "b && c 1 == && x 2 == || a 0 > && c 2 == || a");
        test("test = 15", "test 15 =");
    }

    @Test
    public void test26(){
        test(" system(0, \"hej\");", "0 \"hej\" system:2");
    }

    @Test
    public void test27(){
        test("this.x.y.z++", "this x ] y ] z ] ++");
        test("++this.x.y.z", "this x ] y ] z ] ++");
        test("!this[x(2, 3)].y.z + 2", "this 2 3 x:2 ] y ] z ] ! 2 +");
        test("i++ + 2 + i++", "i ++ 2 + i ++ +");
        test("p = x && y", "p x && y =");
    }

    @Test
    public void test28(){
        test("this.c.sum(5)", "this c ] sum ] 5 ():1");
    }

    public void test(String code, String expected){
        test(code, expected, false);
    }

    public void test(String code, String expected, boolean print){
        Script script = new Script();
        script.setCode(Code.fromStr(code));

        StringBuilder log = new StringBuilder();

        log.append(script.getCode())
           .append("\n");

        ConditionRead condition = new ConditionRead();
        List <Element> elements = condition.read(script);
        try {
            elements = ConditionTransform.before(elements);
        } catch (TransformException e) {
            throw new CompilerException(script);
        }

        log.append(ElementsPrinter.print(elements));

        Infix2Postfix converter = new Infix2Postfix();
        elements = converter.convert(elements);

        try {
            elements = ConditionTransform.after(elements);
        } catch (TransformException e) {
            throw new CompilerException(script);
        }

        elements.forEach(e -> {
            log.append(String.format("%s\t\t%s\n", e.toString(), e.getClass().toString()));
        });

        log.append(ElementsPrinter.print(elements));

        if(print){
            System.out.println(log);
        }

        try {
            check(expected, elements);
        } catch(Exception e){
            System.out.println(log);
        }
    }

    public void check(String expected, List <Element> elements){
        String actual = String.join(" ", (String[])(elements.stream().map(e -> e.toString())
                                                                       .collect(Collectors.toList())
                                                                       .toArray(new String[elements.size()])));

        if(!expected.equals(actual)){
            System.out.println(expected + " >>> " + actual);
            elements.stream()
                    .forEach(e -> {
                        System.out.println(e.getClass());
                    });
        }

        assertEquals(expected, actual);
    }

}
