<TeXmacs|1.99.4>

<style|generic>

<\body>
  STOR 435

  Homework 17

  Siyang Jing

  <\enumerate-numeric>
    <item><math|M<rsub|X><rsup|<around*|(|3|)>><around*|(|t|)>=\<alpha\><around*|(|\<alpha\>+1|)><around*|(|\<alpha\>+2|)>\<lambda\><rsup|\<alpha\>><around*|(|\<lambda\>-t|)><rsup|-\<alpha\>-3>>

    <math|\<bbb-E\><around*|(|X<rsup|3>|)>=M<rsub|X><rsup|<around*|(|3|)>><around*|(|0|)>=<frac|\<alpha\><around*|(|\<alpha\>+1|)><around*|(|\<alpha\>+2|)>|\<lambda\><rsup|3>>=<frac|105|64>\<approx\>1.6406>

    <item>Yes

    <item>Yes

    <item><math|<big|iint><rsub|A><around*|(|x<rsup|2>+x<rsup|>y|)>d<rsup|>x<rsup|>d<rsup|>y=<big|int><rsup|1><rsub|0><big|int><rsup|<sqrt|y>><rsub|0><around*|(|x<rsup|2>+x<rsup|>y|)>d<rsup|>x<rsup|>d<rsup|>y+<big|int><rsup|2><rsub|1><big|int><rsup|1><rsub|0><around*|(|x<rsup|2>+x<rsup|>y|)>d<rsup|>x<rsup|>d<rsup|>y>

    <math|=<big|int><rsup|1><rsub|0><frac|y<rsup|3/2>|3>+<frac|y<rsup|2>|2>d<rsup|>y+<big|int><rsup|2><rsub|1><frac|1|3>+<frac|y|2>d<rsup|>y=<around*|\<nobracket\>|<frac|2|15>y<rsup|<frac|5|2>>+<frac|1|6>y<rsup|3>|\|><rsub|0><rsup|1>+<around*|\<nobracket\>|<frac|1|3>y+<frac|1|4>y<rsup|2>|\|><rsub|1><rsup|2>=<frac|83|60>>

    <math|<big|iint><rsub|A><around*|(|x<rsup|2>+x<rsup|>y|)>d<rsup|>x<rsup|>d<rsup|>y=<big|int><rsup|1><rsub|0><big|int><rsup|2><rsub|x<rsup|2>><around*|(|x<rsup|2>+x<rsup|>y|)>d<rsup|>y<rsup|>d<rsup|>x=<big|int><rsup|1><rsub|0>2x+2x<rsup|2>-x<rsup|4>-<frac|x<rsup|5>|2>d<rsup|>x=<around*|\<nobracket\>|x<rsup|2>+<frac|2|3>x<rsup|3>-<frac|1|5>x<rsup|5>-<frac|1|12>x<rsup|6>|\|><rsub|0><rsup|1>=<frac|83|60>>

    <item><math|\<lambda\>=4>

    <\enumerate-alpha>
      <item><math|M<rsub|X><around*|(|t|)>=<around*|{|<tabular*|<tformat|<table|<row|<cell|<frac|4|4-t>,for
      t\<less\>4>>|<row|<cell|\<infty\>,for
      t\<geqslant\>4>>>>>|\<nobracket\>>>

      <item><math|H<around*|(|t|)>=<around*|{|<tabular*|<tformat|<table|<row|<cell|<around*|(|<frac|4|4-t>|)><rsup|15>,for
      t\<less\>4>>|<row|<cell|\<infty\>,for
      t\<geqslant\>4>>>>>|\<nobracket\>>>

      <item><math|\<lambda\>=4,\<alpha\>=15>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|<around*|(|0,1|)>>

      <item><math|F<rsub|Y><around*|(|y|)>=Pr<around*|(|Y\<less\>y|)>=Pr<around*|(|X<rsup|2>\<less\>y|)>=Pr<around*|(|0\<less\>X\<less\><sqrt|y>|)>+Pr<around*|(|0\<gtr\>X\<gtr\>-<sqrt|y>|)>=2<sqrt|y>-y>

      <item><math|f<rsub|Y><around*|(|y|)>=y<rsup|-<frac|1|2>>-1>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|<around*|(|0,\<infty\>|)>>

      <item><math|F<rsub|Y><around*|(|y|)>=Pr<around*|(|Y\<less\>y|)>=Pr<around*|(|-4log<rsub|e><around*|(|X|)>\<less\>y|)>=Pr<around*|(|X\<gtr\>e<rsup|-4y>|)>=1-e<rsup|-4y>>

      <item><math|f<rsub|Y><around*|(|y|)>=4e<rsup|-4y>>, therefore,
      <math|Y\<sim\>Exp<around*|(|4|)>>, is an exponential distribution.
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|<around*|(|0,\<infty\>|)>>

      <item><math|F<rsub|Y><around*|(|y|)>=Pr<around*|(|Y\<less\>y|)>=Pr<around*|(|365X\<less\>y|)>=Pr<around*|(|X\<less\><frac|y|365>|)>=1-e<rsup|-<frac|y|365>>>

      <item><math|f<rsub|Y><around*|(|y|)>=<frac|1|365>e<rsup|-<frac|y|365>>>
    </enumerate-alpha>
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>