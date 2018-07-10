<TeXmacs|1.99.4>

<style|generic>

<\body>
  <doc-data|<doc-title|STOR 435 Homework 20>|<doc-author|<author-data|<author-name|Siyang
  Jing>>>>

  <\enumerate-numeric>
    <item>No.

    Suppose they are independent, then by definition of independence, we
    would have

    <\equation*>
      p<rsub|X,Y><around*|(|0,1|)>=p<rsub|X><around*|(|0|)>p<rsub|Y><around*|(|1|)>\<neq\>0
    </equation*>

    However, we also have

    <\center>
      <math|p<rsub|X,Y><around*|(|0,1|)>=\<bbb-P\>>(Ruoyu is asked 0
      questions and answers 1 question adequately),
    </center>

    which is apparently 0. Therefore we have a contradiction, and therefore
    they are not independent.

    <item>

    <\enumerate-alpha>
      <item><math|p<rsub|X<rsub|1>,X<rsub|2>,X<rsub|3>><around*|(|x<rsub|1>,x<rsub|2>,x<rsub|3>|)>=p<rsub|X<rsub|1>><around*|(|x<rsub|1>|)>p<rsub|X<rsub|2>><around*|(|x<rsub|2>|)>p<rsub|X<rsub|3>><around*|(|x<rsub|3>|)>=0.0002e<rsup|-0.1x<rsub|1>-0.05x<rsub|2>-0.04x<rsub|3>>>

      <item><math|p<rsub|X<rsub|1>,X<rsub|2>><around*|(|x<rsub|1>,x<rsub|2>|)>=p<rsub|X<rsub|1>><around*|(|x<rsub|1>|)>p<rsub|X<rsub|2>><around*|(|x<rsub|2>|)>=0.005e<rsup|-0.1x<rsub|1>-0.05x<rsub|2>>>

      <item><math|\<bbb-P\><around*|(|X<rsub|1>\<less\>X<rsub|2>|)>=<big|int><rsup|\<infty\>><rsub|0><big|int><rsup|x<rsub|2>><rsub|0>0.005e<rsup|-0.1x<rsub|1>-0.05x<rsub|2>>d<rsup|>x<rsub|1>d<rsup|>x<rsub|2>=<dfrac|2|3>>

      <item><math|\<bbb-P\><around*|(|X<rsub|1>\<leqslant\>10,X<rsub|2>\<leqslant\>10,X<rsub|3>\<gtr\>10|)>=F<rsub|X<rsub|1>><around*|(|10|)>F<rsub|X<rsub|2>><around*|(|10|)><around*|(|1-F<rsub|X<rsub|3>><around*|(|10|)>|)>>

      <math|=<around*|(|1-e<rsup|-0.1*\<times\>10>|)><around*|(|1-e<rsup|-0.05\<times\>10>|)><around*|(|e<rsup|-0.04\<times\>10>|)>\<approx\>0.1667>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|p<rsub|U<rsub|1>,U<rsub|2>,U<rsub|3>><around*|(|u<rsub|1>,u<rsub|2>,u<rsub|3>|)>=p<rsub|U<rsub|1>><around*|(|u<rsub|1>|)>p<rsub|U<rsub|2>><around*|(|u<rsub|2>|)>p<rsub|U<rsub|3>><around*|(|u<rsub|3>|)>=1>

      <item><math|\<bbb-P\><around*|(|max<around*|(|U<rsub|1>,U<rsub|2>,U<rsub|3>|)>\<leqslant\>0.5|)>=\<bbb-P\><around*|(|U<rsub|1>\<leqslant\>0.5,U<rsub|2>\<leqslant\>0.5,U<rsub|3>\<leqslant\>0.5|)>=F<rsub|U<rsub|1>><around*|(|0.5|)>F<rsub|U<rsub|2>><around*|(|0.5|)>F<rsub|U<rsub|2>><around*|(|0.5|)>>

      <math|=<dfrac|0.5-0|1-0>\<times\><dfrac|0.5-0|1-0>\<times\><dfrac|0.5-0|1-0>=<dfrac|1|8>>
    </enumerate-alpha>

    <item><math|\<bbb-E\><around*|(|X<rsup|2><around*|(|Y+1|)><rsup|2>|)>=\<bbb-E\><around*|(|X<rsup|2>|)>\<bbb-E\><around*|(|<around*|(|Y+1|)><rsup|2>|)>=\<bbb-E\><around*|(|X<rsup|2>|)><around*|(|\<bbb-E\><around*|(|Y<rsup|2>|)>+2\<bbb-E\><around*|(|Y|)>+1|)>>

    <math|=<around*|(|Var<around*|(|X|)>+\<bbb-E\><around*|(|X|)><rsup|2>|)><around*|(|Var<around*|(|Y|)>+\<bbb-E\><around*|(|Y|)><rsup|2>+2+1|)>=1\<times\>5=5>

    <item><math|\<bbb-P\><around*|(|W\<leqslant\>0.5|)>=\<bbb-P\><around*|(|Y\<less\>0.5|)>+\<bbb-P\><around*|(|Y\<geqslant\>0.5\<wedge\>X\<leqslant\><rsup|><sqrt|<dfrac|0.5|Y>>|)>>

    <math|=<big|int><rsup|0.5><rsub|0>2y*d<rsup|>y+<big|int><rsup|1><rsub|0.5><rsub|><big|int><rsup|<sqrt|<frac|0.5|y>>><rsub|0>2y6x<around*|(|1-x|)>*d<rsup|>x*d<rsup|>y=<dfrac|1|4>+<big|int><rsup|1><rsub|<frac|1|2>>3-<sqrt|2>y<rsup|-<frac|1|2>>*d<rsup|>y=<frac|15|4>-2<sqrt|2>\<approx\>0.9216>

    <item><math|M<rsub|Y><around*|(|t|)>=M<rsub|X<rsub|1>><around*|(|t|)>M<rsub|X<rsub|2>><around*|(|t|)>M<rsub|X<rsub|3>><around*|(|t|)>=e<rsup|3<around*|(|e<rsup|t>-1|)>>e<rsup|0.5<around*|(|e<rsup|t>-1|)>>e<rsup|2<around*|(|e<rsup|t>-1|)>>=e<rsup|5.5<around*|(|e<rsup|t>-1|)>>>

    <math|p<rsub|Y><around*|(|y|)>=e<rsup|-5.5><dfrac|5.5<rsup|y>|y!>>,
    <math|\<bbb-P\><around*|(|Y=6|)>=p<rsub|Y><around*|(|6|)>\<approx\>0.1571>
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>