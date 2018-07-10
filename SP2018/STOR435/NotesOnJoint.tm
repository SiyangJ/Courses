<TeXmacs|1.99.4>

<style|generic>

<\body>
  Basic Idea: All the information is contained in the cumulative distribution
  of the random variables.

  \;

  <math|F<around*|(|a,b|)>\<assign\>P<around*|(|X\<leqslant\>a\<wedge\>X\<leqslant\>b|)>>

  <\math>
    F<rsub|X><around*|(|a|)>\<assign\>P<around*|(|X\<leqslant\>a|)>=P<around*|(|X\<leqslant\>a,Y\<in\>\<bbb-R\>|)>
  </math>

  <math|F<rsub|Y><around*|(|b|)>\<assign\>P<around*|(|Y\<leqslant\>b|)>=P<around*|(|X\<in\>\<bbb-R\>,Y\<less\>b|)>>

  \;

  <math|P<around*|(|X\<gtr\>a,Y\<gtr\>b|)>=1-P<around*|(|X\<leqslant\>a|)>-P<around*|(|Y\<leqslant\>b|)>+P<around*|(|X\<leqslant\>a\<wedge\>Y\<leqslant\>b|)>=1-F<rsub|X><around*|(|a|)>-F<rsub|Y><around*|(|b|)>+F<around*|(|a,b|)>>

  \;

  <math|P<around*|(|a<rsub|1>\<less\>X\<leqslant\>a<rsub|2>,b<rsub|1>\<less\>Y\<leqslant\>b<rsub|2>|)>=F<around*|(|a<rsub|2>,b<rsub|2>|)>-F<around*|(|a<rsub|1>,b<rsub|2>|)>-F<around*|(|a<rsub|2>,b<rsub|1>|)>+F<around*|(|a<rsub|1>,b<rsub|1>|)>>

  \;

  <math|p<around*|(|x,y|)>=P<around*|(|X=x,Y=y|)>>

  \;

  <math|f<around*|(|x,y|)>,s.t.P<around*|(|<around*|(|X,Y|)>\<in\>C|)>=<big|iint><rsub|<around*|(|x,y|)>\<in\>C>f<around*|(|x,y|)>d<rsup|>x<rsup|>d<rsup|>y>

  \;

  <math|p<rsub|X><around*|(|x|)>=P<around*|(|X=x,Y\<in\>\<bbb-R\>|)>=<big|sum><rsub|y>p<around*|(|x,y|)>>

  \;

  <math|\<bbb-E\><around*|(|X|)>=<big|sum><rsub|x>p<rsub|X><around*|(|x|)>x>

  <math|\<bbb-E\><around*|(|g<around*|(|X|)>|)>=<big|sum><rsub|x>p<rsub|X><around*|(|x|)>g<around*|(|x|)>>,
  as long as <math|g> does not depend on <math|Y>

  \;

  <math|F<around*|(|x,y|)>=P<around*|(|X\<in\><around*|(|-\<infty\>,x|)>,Y\<in\><around*|(|-\<infty\>,y|)>|)>=<big|int><rsup|x><rsub|-\<infty\>><big|int><rsup|y><rsub|-\<infty\>>f<around*|(|\<xi\>,\<psi\>|)>d<rsup|>\<psi\><rsup|>d<rsup|>\<xi\>>,
  by the definition of <math|f>

  Therefore, we have

  <math|f<around*|(|x,y|)>=<dfrac|\<partial\><rsup|2>|\<partial\>x\<partial\>y>F<around*|(|x,y|)>>

  \;

  \;

  <math|f<rsub|X><around*|(|x|)>=<big|int><rsup|\<infty\>><rsub|-\<infty\>>f<around*|(|x,y|)>d<rsup|>y>

  <math|F<rsub|X><around*|(|x|)>=P<around*|(|X\<in\><around*|(|-\<infty\>,x|)>,Y\<in\>\<bbb-R\>|)>=<big|int><rsup|x><rsub|-\<infty\>><big|int><rsup|\<infty\>><rsub|-\<infty\>>f<around*|(|\<xi\>,\<psi\>|)>d<rsup|>\<psi\><rsup|>d<rsup|>\<xi\>=<big|int><rsup|x><rsub|-\<infty\>>f<rsub|X><around*|(|\<xi\>|)>d\<xi\>>

  Therefore, <math|<dfrac|\<partial\>|\<partial\>x>F<rsub|X><around*|(|x|)>>;
  and by the same idea, <math|<dfrac|\<partial\>|\<partial\>y>F<rsub|Y><around*|(|y|)>>

  \;

  Note: This is totally analogous to the 1 variable case, and we don't even
  have to assume independece.

  \;

  <math|\<bbb-E\><around*|(|X|)>=<big|int><rsup|\<infty\>><rsub|-\<infty\>>x<rsup|>f<rsub|X><around*|(|x|)>d<rsup|>x>

  <math|\<bbb-E\><around*|(|g<around*|(|X|)>|)>=<big|int><rsup|\<infty\>><rsub|-\<infty\>>g<around*|(|x|)>f<rsub|X><around*|(|x|)>d<rsup|>x>

  \;

  <paragraph|Example 1c:>

  <math|f<around*|(|x,y|)>=2e<rsup|-x>e<rsup|-2y>,for positive x and y>

  <math|P<around*|(|X\<less\>Y|)>=<big|int><rsup|\<infty\>><rsub|0><big|int><rsup|y><rsub|0>f<around*|(|x,y|)>d<rsup|>x<rsup|>d<rsup|>y=<big|int><rsup|\<infty\>><rsub|0>-2e<rsup|-3y>+2e<rsup|-2y>d<rsup|>y=<dfrac|1|3>>

  \;

  <paragraph|Multinomial Distribution>

  <math|Mul<around*|(|x<rsub|1>,x<rsub|2>,\<ldots\>,x<rsub|r><around*|\||n,p<rsub|1>,p<rsub|2>,\<ldots\>,p<rsub|r>|\<nobracket\>>|)>>,
  probability of\ 

  <math|X<rsub|k>=>#trials which resulted in outcome <math|k>

  Note: <math|<big|sum>x<rsub|k>=n>, and <math|<big|sum><rsub|k>p<rsub|k>=1>

  \;

  <math|p<rsub|X<rsub|1>,X<rsub|2>,\<ldots\>,X<rsub|r><around*|(|x<rsub|1>,x<rsub|2>,\<ldots\>,x<rsub|r>|)>=><dfrac|n!|<big|prod><rsup|k=r><rsub|k=1>x<rsub|k>><big|prod><rsup|k=r><rsub|k=1>p<rsup|x<rsub|k>><rsub|k>>

  \;

  <paragraph|Independence>

  Equivalent conditions

  <\enumerate-numeric>
    <item><math|\<forall\>A,B,P<around*|(|X\<in\>A,Y\<in\>B|)>=P<around*|(|X\<in\>A|)>P<around*|(|Y\<in\>B|)>>

    <item><math|\<forall\>x,y,F<around*|(|x,y|)>=F<rsub|X><around*|(|x|)>F<rsub|Y><around*|(|y|)>>

    <item><math|\<forall\>x,y,p<around*|(|x,y|)>=p<rsub|X><around*|(|x|)>p<rsub|Y><around*|(|y|)>>

    <item><math|\<forall\>x,y,f<around*|(|x,y|)>=f<rsub|X><around*|(|x|)>f<rsub|Y><around*|(|y|)>>

    <item><math|\<exists\>h,g,s.t.\<forall\>x,y,f<around*|(|x,y|)>=h<around*|(|x|)>g<around*|(|y|)>>
  </enumerate-numeric>

  A proof of 2 and 4

  <math|\<Rightarrow\>f<around*|(|x,y|)>=<dfrac|\<partial\><rsup|2>|\<partial\>x\<partial\>y>F<around*|(|x,y|)>=<dfrac|\<partial\><rsup|2>|\<partial\>x\<partial\>y>F<rsub|X><around*|(|x|)>F<rsub|Y><around*|(|y|)>=<dfrac|\<partial\>|\<partial\>x><dfrac|\<partial\>|\<partial\>y>F<rsub|X><around*|(|x|)>F<rsub|Y><around*|(|y|)>=<dfrac|\<partial\>|\<partial\>x>F<rsub|X><around*|(|x|)>f<rsub|Y><around*|(|y|)>=f<rsub|X><around*|(|x|)>f<rsub|Y><around*|(|y|)>>

  <math|\<Leftarrow\>>trivially true through integration.

  \;

  Note: 5 means as long as the function is multiplicatively separable, then
  the variables are independent.

  \;

  <paragraph|Problem from Final Exam 2011>

  <math|p<around*|(|0,0|)>=<dfrac|5|13>\<times\><dfrac|4|12>>

  <math|p<around*|(|1,0|)>=<dfrac|8|13>\<times\><dfrac|5|12>>

  <math|p<around*|(|0,1|)>=<dfrac|5|13>\<times\><dfrac|8|12>>

  <math|p<around*|(|1,1|)>=<dfrac|8|13>\<times\><dfrac|7|12>>

  <\math>
    p<rsub|X><around*|(|0|)>=<dfrac|5|13>
  </math>

  <\math>
    p<rsub|X><around*|(|1|)>=<dfrac|8|13>
  </math>

  <\math>
    p<rsub|Y><around*|(|0|)>=<dfrac|5|13>
  </math>

  <\math>
    p<rsub|Y><around*|(|1|)>=<dfrac|8|13>
  </math>

  So no, they are not independent, which is in accordance with intuition.

  \;

  <paragraph|Sums of Independent Random Variables>

  <math|f<rsub|X+Y><around*|(|a|)>=<around*|(|f<rsub|X>\<ast\>f<rsub|Y>|)><around*|(|a|)>\<assign\><big|int><rsup|\<infty\>><rsub|-\<infty\>>f<rsub|X><around*|(|t|)>f<rsub|Y><around*|(|a-t|)>d<rsup|>t>,
  the convolution of the pdf's.

  <math|p<rsub|X+Y><around*|(|a|)>=<big|sum><rsup|t=\<infty\>><rsub|t=-\<infty\>>p<rsub|X><around*|(|t|)>p<rsub|Y><around*|(|a-t|)>>

  \;

  \;

  <math|>

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|?>>
    <associate|auto-2|<tuple|2|?>>
    <associate|auto-3|<tuple|3|?>>
    <associate|auto-4|<tuple|4|?>>
    <associate|auto-5|<tuple|5|?>>
    <associate|auto-6|<tuple|6|?>>
    <associate|auto-7|<tuple|6.1|?>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <with|par-left|<quote|4tab>|Example 1c:
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.15fn>>

      <with|par-left|<quote|4tab>|Multinomial Distribution
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-2><vspace|0.15fn>>

      <with|par-left|<quote|4tab>|Independence
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-3><vspace|0.15fn>>

      <with|par-left|<quote|4tab>|Problem from Final Exam 2011
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-4><vspace|0.15fn>>

      <with|par-left|<quote|4tab>|Sums of Independent Random Variables
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-5><vspace|0.15fn>>
    </associate>
  </collection>
</auxiliary>