<TeXmacs|1.99.4>

<style|generic>

<\body>
  <doc-data|<doc-title|STOR 435 Homework 21>|<doc-author|<\author-data|<author-name|Siyang
  Jing>>
    \;
  </author-data>>>

  <\enumerate-numeric>
    <item>

    <\enumerate-alpha>
      <item><math|M<rsub|Y><around*|(|t|)>=<big|prod><rsup|i=30><rsub|i=1>M<rsub|X<rsub|i>><around*|(|t|)>=<around*|(|<dfrac|\<lambda\>|\<lambda\>-t>|)><rsup|30>>

      <math|Y\<sim\>Gamma<around*|(|\<alpha\>=30,\<lambda\>=<dfrac|1|8>|)>>,
      <math|f<rsub|Y><around*|(|y|)>=<dfrac|1|8<rsup|30>\<Gamma\><around*|(|\<alpha\>|)>>x<rsup|29>e<rsup|-<frac|x|8>>>

      <item><math|M<rsub|<wide|Y|\<bar\>>><around*|(|t|)>=\<bbb-E\><around*|(|e<rsup|t<frac|Y|30>>|)>=M<rsub|Y><around*|(|<dfrac|t|30>|)>=<around*|(|<dfrac|\<lambda\>|\<lambda\>-<frac|t|30>>|)><rsup|30>=<around*|(|<dfrac|30\<lambda\>|30\<lambda\>-t>|)><rsup|30>>

      <math|<wide|Y|\<bar\>>\<sim\>Gamma<around*|(|\<alpha\>=30,\<lambda\>=<dfrac|15|4>|)>>,
      <math|><math|f<rsub|Y><around*|(|y|)>=<dfrac|15<rsup|30>|4<rsup|30>\<Gamma\><around*|(|\<alpha\>|)>>x<rsup|29>e<rsup|-<frac|15x|4>>>
    </enumerate-alpha>

    <item>We first note that for a normal random variable
    <math|X\<sim\>N<around*|(|\<mu\>,\<sigma\><rsup|2>|)>>,
    <math|a<rsup|>X\<sim\>N<around*|(|a\<mu\>,a<rsup|2>\<sigma\><rsup|2>|)>>

    <\enumerate-alpha>
      <item><math|M<rsub|Y><around*|(|t|)>=M<rsub|X<rsub|1>><around*|(|2t|)>M<rsub|X<rsub|2>><around*|(|-3t|)>M<rsub|X<rsub|3>><around*|(|-5t|)>=e<rsup|<around*|(|2\<mu\><rsub|1>-3\<mu\><rsub|2>-5\<mu\><rsub|3>|)>t+<dfrac|4\<sigma\><rsup|2><rsub|1>+9\<sigma\><rsup|2><rsub|2>+25\<sigma\><rsup|2><rsub|3>|2>t<rsup|2>>=e<rsup|-31t+<dfrac|2077|2>t<rsup|2>>>

      <math|Y\<sim\>N<around*|(|\<mu\>=-31,\<sigma\><rsup|2>=2077|)>>

      <item><math|\<bbb-P\><around*|(|Y\<gtr\>3|)>=1-F<rsub|Y><around*|(|3|)>\<approx\>0.2278>
    </enumerate-alpha>

    <item><math|\<bbb-E\><around*|(|X<rsup|2>|)>=Var<around*|(|X|)>+\<bbb-E\><around*|(|X|)><rsup|2>=8>,
    <math|\<bbb-E\><around*|(|Y<rsup|2>|)>=Var<around*|(|Y|)>+\<bbb-E\><around*|(|Y|)><rsup|2>=18>,
    <math|\<bbb-E\><around*|(|Z<rsup|2>|)>=Var<around*|(|Z|)>+\<bbb-E\><around*|(|Z|)><rsup|2>=37>

    <\enumerate-alpha>
      <item><math|\<bbb-E\><around*|(|g<around*|(|X,Y,Z|)>|)>=2+\<bbb-E\><around*|(|Y|)>\<bbb-E\><around*|(|Z|)>-3\<bbb-E\><around*|(|X<rsup|2>|)>\<bbb-E\><around*|(|Y|)>+6\<bbb-E\><around*|(|X<rsup|2>|)>\<bbb-E\><around*|(|Y<rsup|2>|)>\<bbb-E\><around*|(|Z<rsup|2>|)>=31901>

      <item><math|\<bbb-P\><around*|(|2X+Y\<geqslant\>Z-Y|)>=\<bbb-P\><around*|(|2X+2Y-Z\<geqslant\>0|)>>
      <math|<around*|(|\<ast\>|)>>

      <math|W\<assign\>2X+2Y-Z\<sim\>N<around*|(|\<mu\>=1,\<sigma\><rsup|2>=88|)>>,
      therefore <math|<around*|(|\<ast\>|)>=1-F<rsub|W><around*|(|0|)>\<approx\>0.5424>
    </enumerate-alpha>

    <item><math|Y\<sim\>N<around*|(|\<mu\>=20\<times\>10+30\<times\>11,\<sigma\><rsup|2>=20<rsup|2>\<times\>1+30<rsup|2>\<times\>1.2|)>\<sim\>N<around*|(|\<mu\>=530,\<sigma\><rsup|2>=1480|)>>

    <math|\<bbb-P\><around*|(|Y\<gtr\>480|)>=1-F<rsub|Y><around*|(|480|)>=0.5135>

    <item>

    <\enumerate-alpha>
      <item><math|<big|int><rsup|1><rsub|0><big|int><rsup|1><rsub|0>c<around*|(|x<rsup|2>+y<rsup|2>|)>d<rsup|>x<rsup|>d<rsup|>y=c<dfrac|2|3>=1\<Rightarrow\>c=<dfrac|3|2>>

      <math|f<rsub|Y><around*|(|y|)>=<big|int><rsup|1><rsub|0>c<around*|(|x<rsup|2>+y<rsup|2>|)>d<rsup|>x=<dfrac|1|2>+<dfrac|3|2>y<rsup|2>>

      <item><math|f<rsub|X<around*|\|||\<nobracket\>>Y><around*|(|x<around*|\|||\<nobracket\>>y|)>=<dfrac|f<rsub|X,Y><around*|(|x,y|)>|f<rsub|Y><around*|(|y|)>>=<dfrac|c<around*|(|x<rsup|2>+y<rsup|2>|)>|c<around*|(|<frac|1|3>+y<rsup|2>|)>>=<dfrac|x<rsup|2>+y<rsup|2>|1/3+y<rsup|2>>>

      <item><math|\<bbb-P\><around*|(|1/4\<less\>X\<less\>1/2<around*|\|||\<nobracket\>>Y=3/4|)>=<big|int><rsup|1/2><rsub|1/4><dfrac|x<rsup|2>+<around*|(|3/4|)><rsup|2>|1/3+<around*|(|3/4|)><rsup|2>>d<rsup|>x=<dfrac|17|86>>
    </enumerate-alpha>
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>