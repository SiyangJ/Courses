<TeXmacs|1.99.4>

<style|generic>

<\body>
  STOR 435

  Homework 16

  Siyang Jing

  \;

  <\enumerate-numeric>
    <item>Yes

    <item>Yes

    <item>Yes

    <item><math|<big|int><rsup|1><rsub|0><big|int><rsup|2><rsub|0>cos<around*|(|x+y|)>d<rsup|>x<rsup|>d<rsup|>y=<big|int><rsup|1><rsub|0><rsup|><around*|\<nobracket\>|sin<around*|(|x+y|)>|\|><rsub|0><rsup|2>d<rsup|>y=<big|int><rsup|1><rsub|0><rsup|>sin<around*|(|2+y|)>-sin<around*|(|y|)>d<rsup|>y=<around*|\<nobracket\>|cos<around*|(|y|)>-cos<around*|(|2+y|)>|\|><rsub|0><rsup|1>>

    <\math>
      =cos<around*|(|1|)>-cos<around*|(|3|)>-cos<around*|(|0|)>+cos<around*|(|2|)>\<approx\>0.1141
    </math>

    <item><math|\<bbb-E\><around*|(|X|)>=\<lambda\><rsup|-1>=2\<rightarrow\>\<lambda\>=<frac|1|2>\<rightarrow\>X\<sim\>Exp<around*|(|<frac|1|2>|)>>

    <math|F<rsub|X><around*|(|x|)>=1-e<rsup|-<frac|1|2>x>>

    <\enumerate-alpha>
      <item><math|F<rsub|X><around*|(|1|)>=1-e<rsup|-<frac|1|2>\<times\>1>=0.3935>

      <item><math|F<rsub|X><around*|(|<frac|1|2>|)>=1-e<rsup|-<frac|1|2>\<times\><frac|1|2>>=0.2212>

      <item><math|F<rsub|X><around*|(|10|)>=1-e<rsup|-<frac|1|2>\<times\>10>=0.9933>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|1-expcdf<around*|(|2,1|)>=e<rsup|-1\<times\>2>=0.1353>

      <item><math|Pr<around*|(|X\<gtr\>10<around*|\|||\<nobracket\>>X\<gtr\>9|)>=<frac|Pr<around*|(|X\<gtr\>10\<wedge\>X\<gtr\>9|)>|Pr<around*|(|x\<gtr\>9|)>>=<frac|Pr<around*|(|X\<gtr\>10|)>|Pr<around*|(|X\<gtr\>9|)>>=e<rsup|-1<around*|(|10-9|)>>=0.3679>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|F<rsub|X><around*|(|x|)>=1-e<rsup|-<frac|1|4>x>>

      <item>16

      <item><math|H<around*|(|a|)>=\<bbb-E\><around*|(|X-a|)><rsup|2>=\<bbb-E\><around*|(|X<rsup|2>|)>-2a\<bbb-E\><around*|(|X|)>+a<rsup|2>=2\<lambda\><rsup|-2>-2a\<lambda\><rsup|-1>+a<rsup|2>>

      <math|<around*|(|<frac|\<partial\>H<around*|(|a|)>|\<partial\>a>|)><rsub|a=<wide|a|^>>=0\<rightarrow\>2<wide|a|^>-2\<lambda\><rsup|-1>=0\<rightarrow\><wide|a|^>=\<lambda\><rsup|-1>=4>

      \;
    </enumerate-alpha>

    <item>Let <math|Y\<sim\>Exp<around*|(|<frac|1|5>|)>>

    <math|Pr<around*|(|X=a|)>=Pr<around*|(|a-1\<leqslant\>Y\<less\>a|)>=F<rsub|Y><around*|(|a|)>-F<rsub|Y><around*|(|a-1|)>=e<rsup|-<frac|1|5><around*|(|a-1|)>>-e<rsup|-<frac|1|5>a>=<around*|(|e<rsup|<frac|1|5>>-1|)>e<rsup|-<frac|1|5>a>>
  </enumerate-numeric>

  \;

  Notes on exponential random variable:

  <math|F<rsub|X><around*|(|a|)>=<big|int><rsup|a><rsub|0>\<lambda\>e<rsup|-\<lambda\><rsup|>x><rsup|>d<rsup|>x=-<around*|(|e<rsup|-\<lambda\>x>|)><rsub|0><rsup|a>=1-e<rsup|-\<lambda\>a>>

  <math|\<bbb-E\><around*|(|X|)>=<big|int><rsup|\<infty\>><rsub|0>\<lambda\>e<rsup|-\<lambda\><rsup|>x>x<rsup|>d<rsup|>x=-<big|int><rsup|\<infty\>><rsub|0>x<rsup|>d<rsup|>e<rsup|-\<lambda\><rsup|>x>=-<around*|(|x<rsup|>e<rsup|-\<lambda\>x>+\<lambda\><rsup|-1>e<rsup|-\<lambda\>x>|)><rsub|0><rsup|\<infty\>>=\<lambda\><rsup|-1>>

  <math|M<rsub|X><around*|(|t|)>=\<bbb-E\><around*|(|e<rsup|t<rsup|>X>|)>=<big|int><rsup|\<infty\>><rsub|0>\<lambda\>e<rsup|<around*|(|t-\<lambda\>|)><rsup|>x><rsup|>d<rsup|>x=<around*|(|<frac|\<lambda\>|t-\<lambda\>>e<rsup|<around*|(|t-\<lambda\>|)>x>|)><rsub|0><rsup|\<infty\>>=<frac|\<lambda\>|\<lambda\>-t>>,
  for <math|t\<less\>\<lambda\>>.

  <math|\<bbb-E\><around*|(|X<rsup|2>|)>=M<rprime|''><rsub|X><around*|(|0|)>=2\<lambda\><around*|(|\<lambda\>-0|)><rsup|-3>=2\<lambda\><rsup|-2>>

  <math|Var<around*|(|X|)>=\<bbb-E\><around*|(|X<rsup|2>|)>-<around*|(|\<bbb-E\>X|)><rsup|2>=2\<lambda\><rsup|-2>-\<lambda\><rsup|-2>=\<lambda\><rsup|-2>>

  \;

  \;

  \;

  \;

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>