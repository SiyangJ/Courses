<TeXmacs|1.99.4>

<style|generic>

<\body>
  <doc-data|<doc-title|STOR 435 Homework 19>|<doc-author|<author-data|<author-name|Siyang
  Jing>>>>

  <\enumerate-numeric>
    <item><math|n=46>; <math|p<rsub|1>=p<rsub|3>=p<rsub|5>=p<rsub|7>=p<rsub|8>=p<rsub|10>=p<rsub|12>=<dfrac|31|365>>,
    <math|p<rsub|4>=p<rsub|6>=p<rsub|9>=p<rsub|11>=<dfrac|30|365>>,
    <math|p<rsub|2>=<dfrac|28|365>>

    <item>

    <\enumerate-alpha>
      <item>Apparently <math|<around*|(|X<rsub|1>,X<rsub|2>,X<rsub|3>|)>>
      obeys a multinomial distribution, with

      <math|n=150,> <math|p<rsub|1>=p<rsup|2>>,
      <math|p<rsub|2>=2p<around*|(|1-p|)>>,
      <math|p<rsub|3>=<around*|(|1-p|)><rsup|2>>

      Therefore, the pmf for <math|<around*|(|X<rsub|1>,X<rsub|2>,X<rsub|3>|)>>
      is:

      <math|p<rsub|X<rsub|1>,X<rsub|2>,X<rsub|3>><around*|(|x<rsub|1>,x<rsub|2>,x<rsub|3>|)>=<dfrac|150!|x<rsub|1>!x<rsub|2>!x<rsub|3>!>p<rsup|2x<rsub|1>><around*|(|2p<around*|(|1-p|)>|)><rsup|x<rsub|2>><around*|(|1-p|)><rsup|2x<rsub|3>>=<dfrac|150!|x<rsub|1>!x<rsub|2>!x<rsub|3>!>2<rsup|x<rsub|2>>p<rsup|2x<rsub|1>+x<rsub|2>><around*|(|1-p|)><rsup|2x<rsub|3>+x<rsub|2>>>

      <item><math|<around*|(|X<rsub|1>+X<rsub|2>,X<rsub|3>|)>> also obeys a
      multinomial distribution, with

      <math|n=150,> <math|p<rsub|1+2>=p<rsup|2>+2p<around*|(|1-p|)>=p<around*|(|2-p|)>>,
      <math|p<rsub|3>=<around*|(|1-p|)><rsup|2>>

      Therefore, the pmf for <math|<around*|(|X<rsub|1>+X<rsub|2>,X<rsub|3>|)>>
      is:

      <math|p<rsub|X<rsub|1>+X<rsub|2>,X<rsub|3>><around*|(|a,b|)>=<dfrac|150!|a!b!><around*|(|p<around*|(|2-p|)>|)><rsup|a><around*|(|1-p|)><rsup|2b>>

      <item><math|g<around*|(|p|)>=><math|p<rsub|X<rsub|1>,X<rsub|2>,X<rsub|3>><around*|(|45,80,25|)>=<dfrac|150!|45!80!25!>p<rsup|90><around*|(|2p<around*|(|1-p|)>|)><rsup|80><around*|(|1-p|)><rsup|50>=<dfrac|150!2<rsup|80>|45!80!25!>p<rsup|170><around*|(|1-p|)><rsup|130>>

      <\math>
        =520125087180721124443178586055284386474151575007050587134406698894686786790633347481600
        (1- p)<rsup|130>p<rsup|170>
      </math>

      <item>Let <math|c=<dfrac|150!2<rsup|80>|45!80!25!>>,
      <math|<dfrac|\<partial\>|\<partial\>p>g<around*|(|p|)>=c<dfrac|\<partial\>|\<partial\>p>p<rsup|170><around*|(|1-p|)><rsup|130>=c<around*|(|170-300p|)>p<rsup|169><around*|(|1-p|)><rsup|129>>.

      Let <math|<wide|p|^>\<assign\><below|argmax|p\<in\><around*|[|0,1|]>><around*|(|g<around*|(|p|)>|)>>.

      We observe that <math|g<around*|(|0|)>=g<around*|(|1|)>=0>, and that
      when <math|p\<in\><around*|(|0,1|)>>, <math|g<around*|(|p|)>\<gtr\>0>.
      We also observe that <math|<dfrac|\<partial\>|\<partial\>p>g<around*|(|p|)>>
      has only one zero on <math|*<around*|(|0,1|)>>, and therefore,
      <math|<dfrac|\<partial\>|\<partial\>p>g<around*|(|<wide|p|^>|)>=0>.

      \ <math|<dfrac|\<partial\>|\<partial\>p>g<around*|(|<wide|p|^>|)>=0\<Leftrightarrow\>c<around*|(|170-300<wide|p|^>|)><wide|p|^><rsup|169><around*|(|1-<wide|p|^>|)><rsup|129>=0\<Leftrightarrow\>170-300<wide|p|^>=0\<Leftrightarrow\><wide|p|^>=<dfrac|17|30>>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|<big|int><rsup|1><rsub|0><big|int><rsup|y><rsub|0>c*x<rsup|2>y<rsup|2>d<rsup|>x<rsup|>d<rsup|>y=<big|int><rsup|1><rsub|0><dfrac|c|3>y<rsup|5>d<rsup|>y=<dfrac|c|18>=1\<Leftrightarrow\>c=18>

      <item><math|f<rsub|X><around*|(|x|)>=><around*|{|<tabular|<tformat|<table|<row|<cell|<math|<big|int><rsup|1><rsub|x>18x<rsup|2>y<rsup|2>d<rsup|>y=6x<rsup|2>-6x<rsup|5>>>|<cell|if
      <math|0\<leqslant\>x\<leqslant\>1>>>|<row|<cell|0>|<cell|otherwise.>>>>>|\<nobracket\>>

      <item><math|f<rsub|Y><around*|(|y|)>=><around*|{|<tabular|<tformat|<table|<row|<cell|<math|<big|int><rsup|y><rsub|0>18x<rsup|2>y<rsup|2>d<rsup|>x=6y<rsup|5>>>|<cell|if
      <math|0\<leqslant\>y\<leqslant\>1>>>|<row|<cell|0>|<cell|otherwise.>>>>>|\<nobracket\>>

      <item>Generally, <math|f<around*|(|x,y|)>\<neq\>f<rsub|X><around*|(|x|)>f<rsub|Y><around*|(|y|)>>,
      and therefore, they are not independent.
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|f<rsub|X><around*|(|x|)>=><around*|{|<tabular|<tformat|<table|<row|<cell|<math|<big|int><rsup|1><rsub|0>x+y<rsup|>d<rsup|>y=x+<dfrac|1|2>>>|<cell|if
      <math|0\<less\>x\<less\>1>>>|<row|<cell|0>|<cell|otherwise.>>>>>|\<nobracket\>>

      <item><math|f<rsub|Y><around*|(|y|)>=><around*|{|<tabular|<tformat|<table|<row|<cell|<math|<big|int><rsup|1><rsub|0>x+y<rsup|>d<rsup|>x=y+<dfrac|1|2>>>|<cell|if
      <math|0\<less\>x\<less\>1>>>|<row|<cell|0>|<cell|otherwise.>>>>>|\<nobracket\>>

      <item>Generally, <math|f<around*|(|x,y|)>\<neq\>f<rsub|X><around*|(|x|)>f<rsub|Y><around*|(|y|)>>,
      and therefore, they are not independent.
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|f<around*|(|r,s|)>=f<rsub|R><around*|(|r|)>f<rsub|S><around*|(|s|)>=1>

      <item><math|P<around*|(|h<around*|(|x|)>has real
      roots|)>=P<around*|(|S<rsup|2>-4R\<geqslant\>0|)>>

      We first find probability distribution of <math|S<rsup|2>> and
      <math|-4R>:

      <math|F<rsub|S<rsup|2>><around*|(|a|)>=F<rsub|S><around*|(|<sqrt|a>|)>=<sqrt|a>>,
      <math|a\<in\><around*|[|0,1|]>>

      <math|f<rsub|S<rsup|2>><around*|(|a|)>=<dfrac|1|2>a<rsup|-<frac|1|2>>>,
      <math|a\<in\><around*|[|0,1|]>>

      <math|F<rsub|-4R><around*|(|a|)>=1-F<rsub|R><around*|(|-<dfrac|a|4>|)>=1+<dfrac|a|4>>,
      <math|a\<in\><around*|[|-4,0|]>>

      <math|f<rsub|-4R><around*|(|a|)>=<dfrac|1|4>>,
      <math|a\<in\><around*|[|-4,0|]>>

      <math|f<rsub|S<rsup|2>-4R><around*|(|a|)>=<big|int><rsup|\<infty\>><rsub|-\<infty\>>f<rsub|S<rsup|2>><around*|(|t|)>f<rsub|-4R<rsup|2>><around*|(|a-t|)>d<rsup|>t=><around*|{|<tabular|<tformat|<table|<row|<cell|<math|<big|int><rsup|a+4><rsub|0><dfrac|1|2>t<rsup|-<frac|1|2>><dfrac|1|4>d<rsup|>t=<dfrac|1|4><around*|(|a+4|)><rsup|<frac|1|2>>>>|<cell|if
      <math|a\<in\><around*|[|-4,-3|]>>>>|<row|<cell|<math|<big|int><rsup|1><rsub|0><dfrac|1|2>t<rsup|-<frac|1|2>><dfrac|1|4>d<rsup|>t=<dfrac|1|4>>>|<cell|if
      <math|a\<in\><around*|[|-3,0|]>>>>|<row|<cell|<math|<big|int><rsup|1><rsub|a><dfrac|1|2>t<rsup|-<frac|1|2>><dfrac|1|4>d<rsup|>t=<dfrac|1|4>-<dfrac|1|4>a<rsup|<frac|1|2>>>>|<cell|if
      <math|a\<in\><around*|[|0,1|]>>>>|<row|<cell|0>|<cell|otherwise>>>>>|\<nobracket\>>

      <math|P<around*|(|S<rsup|2>-4R\<geqslant\>0|)>=<big|int><rsup|1><rsub|0><dfrac|1|4>-<dfrac|1|4>a<rsup|<frac|1|2>>d<rsup|>a=<dfrac|1|12>>
    </enumerate-alpha>
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>