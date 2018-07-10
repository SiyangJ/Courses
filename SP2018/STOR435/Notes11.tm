<TeXmacs|1.99.4>

<style|generic>

<\body>
  Notes on Gamma distribution:

  <\equation*>
    f<around*|(|x|)>=<frac|\<lambda\>e<rsup|-\<lambda\>x><around*|(|\<lambda\>x|)><rsup|\<alpha\>-1>|\<Gamma\><around*|(|\<alpha\>|)>>,x\<gtr\>0
  </equation*>

  <\equation*>
    \<Gamma\><around*|(|\<alpha\>|)>=<big|int><rsup|\<infty\>><rsub|0>e<rsup|-y>y<rsup|\<alpha\>-1>d<rsup|>y
  </equation*>

  <math|\<Gamma\><around*|(|\<alpha\>|)>> is simply the normalizing factor.

  Note:

  <math|\<Gamma\><around*|(|\<alpha\>|)>> is the generalization of factorial
  into real numbers (actually into complex numbers except negative integers),
  i.e. <math|\<Gamma\><around*|(|\<alpha\>+1|)>=\<alpha\>\<Gamma\><around*|(|\<alpha\>|)>>

  \;

  <math|M<rsub|X><around*|(|x|)>=\<bbb-E\><around*|(|e<rsup|t<rsup|>x>|)>=<frac|1|\<Gamma\><around*|(|\<alpha\>|)>><big|int><rsup|\<infty\>><rsub|0>e<rsup|t<rsup|>x>\<lambda\>e<rsup|-\<lambda\>x><around*|(|\<lambda\>x|)><rsup|\<alpha\>-1>d<rsup|>x=<frac|1|\<Gamma\><around*|(|\<alpha\>|)>><big|int><rsup|\<infty\>><rsub|0>\<lambda\>e<rsup|-<around*|(|\<lambda\>-t|)>x><around*|(|\<lambda\>x|)><rsup|\<alpha\>-1>d<rsup|>x>

  <math|=<frac|1|\<Gamma\><around*|(|\<alpha\>|)>><around*|(|<frac|\<lambda\>|\<lambda\>-t>|)><rsup|\<alpha\>><big|int><rsup|\<infty\>><rsub|0><around*|(|\<lambda\>-t|)>e<rsup|-<around*|(|\<lambda\>-t|)>x><around*|(|<around*|(|\<lambda\>-t|)>x|)><rsup|\<alpha\>-1>d<rsup|>x=<frac|\<Gamma\><around*|(|\<alpha\>|)>|\<Gamma\><around*|(|\<alpha\>|)>><around*|(|<frac|\<lambda\>|\<lambda\>-t>|)><rsup|\<alpha\>>=<around*|(|<frac|\<lambda\>|\<lambda\>-t>|)><rsup|\<alpha\>>=\<lambda\><rsup|\<alpha\>><around*|(|\<lambda\>-t|)><rsup|-\<alpha\>>>,
  for <math|\<lambda\>\<gtr\>t>

  <math|M<rprime|'><rsub|X><around*|(|t|)>=\<alpha\><around*|(|<frac|\<lambda\>|\<lambda\>-t>|)><rsup|\<alpha\>-1>\<lambda\><around*|(|\<lambda\>-t|)><rsup|-2>=\<alpha\><around*|(|<frac|\<lambda\>|\<lambda\>-t>|)><rsup|\<alpha\>><around*|(|\<lambda\>-t|)><rsup|-1>=\<alpha\>\<lambda\><rsup|\<alpha\>><around*|(|\<lambda\>-t|)><rsup|-\<alpha\>-1>>

  <math|\<bbb-E\><around*|(|X|)>=M<rsub|X><rprime|'><around*|(|0|)>=<frac|\<alpha\>|\<lambda\>>>

  <math|M<rsub|X><rprime|''><around*|(|t|)>=\<alpha\><around*|(|\<alpha\>+1|)>\<lambda\><rsup|\<alpha\>><around*|(|\<lambda\>-t|)><rsup|-\<alpha\>-2>=\<alpha\><around*|(|\<alpha\>+1|)><around*|(|<frac|\<lambda\>|\<lambda\>-t>|)><rsup|\<alpha\>><around*|(|\<lambda\>-t|)><rsup|-2>>

  <math|\<bbb-E\><around*|(|X<rsup|2>|)>=M<rsub|X><rprime|''><around*|(|0|)>=<frac|\<alpha\><around*|(|\<alpha\>+1|)>|\<lambda\><rsup|2>>>

  <math|Var<around*|(|X|)>=\<bbb-E\><around*|(|X<rsup|2>|)>-\<bbb-E\>X<rsup|2>=<frac|\<alpha\>|\<lambda\><rsup|2>>>

  \;

  Example 1c:

  <math|P<around*|(|X\<less\>Y|)>=<big|int><rsup|\<infty\>><rsub|0><big|int><rsup|y><rsub|0>f<around*|(|x,y|)>d<rsup|>x<rsup|>d<rsup|>y=<big|int><rsup|\<infty\>><rsub|0>2e<rsup|-2y><around*|(|1-e<rsup|-y>|)>d<rsup|>y=<around*|\<nobracket\>|-e<rsup|-2y>+<frac|2|3>e<rsup|-3y>|\|><rsub|0><rsup|\<infty\>>=<frac|1|3>>

  \;

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>