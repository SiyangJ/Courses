<TeXmacs|1.99.4>

<style|generic>

<\body>
  <doc-data|<doc-title|STOR 435 Homework 24>|<doc-author|<author-data|<author-name|Siyang
  Jing>>>>

  <\enumerate-numeric>
    <item>

    <\enumerate-alpha>
      <item>We first notice that <math|Y<around*|\|||\<nobracket\>>X=x\<sim\>B<around*|(|x,0.75|)>>

      <math|p<rsub|X,Y><around*|(|x,y|)>=p<rsub|Y<around*|\|||\<nobracket\>>X><around*|(|y<around*|\|||\<nobracket\>>x|)>p<rsub|X><around*|(|x|)>=<dfrac|1|6><choose|x|y><around*|(|0.75|)><rsup|y><around*|(|1-0.75|)><rsup|x-y>=<dfrac|<choose|x|y>4<rsup|-x>3<rsup|y>|6>>,\ 

      for <math|0\<leqslant\>y>, <math|max<around*|(|y,1|)>\<leqslant\>x\<leqslant\>6>

      <math|p<rsub|X,Y><around*|(|x,y|)>=0>, for other values.

      <item><math|p<rsub|Y><around*|(|y|)>=<big|sum><rsup|i=6><rsub|i=max<around*|(|y,1|)>>p<rsub|X,Y><around*|(|i,y|)>=<big|sum><rsup|i=6><rsub|i=max<around*|(|y,1|)>><dfrac|<choose|i|y>4<rsup|-i>3<rsup|y>|6>>,
      for <math|0\<leqslant\>y\<leqslant\>6>

      // TODO, can simplify?

      <math|p<rsub|X<around*|\|||\<nobracket\>>Y><around*|(|x<around*|\|||\<nobracket\>>3|)>=<dfrac|p<rsub|X,Y><around*|(|x,3|)>|p<rsub|Y><around*|(|3|)>>>

      // TODO, closed form?

      <math|<tabular*|<tformat|<cwith|1|-1|1|-1|cell-tborder|1ln>|<cwith|1|-1|1|-1|cell-bborder|1ln>|<cwith|1|-1|1|-1|cell-lborder|1ln>|<cwith|1|-1|1|-1|cell-rborder|1ln>|<table|<row|<cell|x>|<cell|1>|<cell|2>|<cell|3>|<cell|4>|<cell|5>|<cell|6>>|<row|<cell|p<rsub|X<around*|\|||\<nobracket\>>Y><around*|(|x<around*|\|||\<nobracket\>>3|)>>|<cell|0>|<cell|0>|<cell|0.3404>|<cell|0.3404>|<cell|0.2128>|<cell|0.1064>>>>>>

      <item>4.0851

      // TODO, close form?
    </enumerate-alpha>

    <item><math|Cov<around*|(|X,Y|)>=\<rho\><sqrt|Var<around*|(|X|)>Var<around*|(|Y|)>>=-0.3<sqrt|4<rsup|2>\<times\>17.6<rsup|2>>=-21.12>

    <math|Var<around*|(|R|)>=0.4<rsup|2>Var<around*|(|X|)>+0.6<rsup|2>Var<around*|(|Y|)>+2\<times\>0.4\<times\>0.6Cov<around*|(|X,Y|)>=103.936>

    <math|\<sigma\><rsub|R>=<sqrt|Var<around*|(|R|)>>\<approx\>10.1949>

    <item>

    <\enumerate-alpha>
      <item>No. Suppose <math|X> and <math|Y> are independent, then we have
      <math|p<rsub|X,Y><around*|(|x,y|)>=p<rsub|X><around*|(|x|)>p<rsub|Y><around*|(|y|)>>

      <math|<around*|\<nobracket\>|<tabular*|<tformat|<table|<row|<cell|p<rsub|X,Y><around*|(|1,2|)>\<neq\>0\<rightarrow\>p<rsub|X><around*|(|1|)>\<neq\>0>>|<row|<cell|p<rsub|X,Y><around*|(|2,3|)>\<neq\>0\<rightarrow\>p<rsub|Y><around*|(|3|)>\<neq\>0>>>>>|}>\<rightarrow\>p<rsub|X,Y><around*|(|1,3|)>=p<rsub|X><around*|(|1|)>p<rsub|Y><around*|(|3|)>\<neq\>0>,
      contradiction.

      Therefore, <math|X> and <math|Y> are not independent.

      Note: This means if independent, 0 has to appear along at least one
      dimension.

      <item>0.5150

      <item>0.6314
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|Cov<around*|(|Y<rsub|n>,Y<rsub|n+j>|)>=Cov<around*|(|X<rsub|n>+2X<rsub|n+1>,X<rsub|n+j>+2X<rsub|n+1+j>|)>>

      <\math>
        =Cov<around*|(|X<rsub|n>,X<rsub|n+j>|)>+2Cov<around*|(|X<rsub|n>,X<rsub|n+1+j>|)>+2Cov<around*|(|X<rsub|n+1>,X<rsub|n+j>|)>+4Cov<around*|(|X<rsub|n+1>,X<rsub|n+1+j>|)>
      </math>

      <math|=0>

      Therefore, <math|\<rho\><rsub|Y<rsub|n>,Y<rsub|n+j>>=<dfrac|Cov<around*|(|Y<rsub|n>,Y<rsub|n+j>|)>|<sqrt|Var<around*|(|Y<rsub|n>|)>Var<around*|(|Y<rsub|n+j>|)>>>=0>

      <item><math|Cov<around*|(|Y<rsub|n>,Y<rsub|n+1>|)>=Cov<around*|(|X<rsub|n>+2X<rsub|n+1>,X<rsub|n+1>+2X<rsub|n+2>|)>>

      <math|=Cov<around*|(|X<rsub|n>,X<rsub|n+1>|)>+2Cov<around*|(|X<rsub|n>,X<rsub|n+2>|)>+2Cov<around*|(|X<rsub|n+1>,X<rsub|n+1>|)>+4Cov<around*|(|X<rsub|n+1>,X<rsub|n+2>|)>>

      <math|=2Var<around*|(|X<rsub|n+1>|)>=2\<sigma\><rsup|2>>

      <math|Var<around*|(|Y<rsub|n>|)>=Var<around*|(|X<rsub|n>+2X<rsub|n+1>|)>=Var<around*|(|X<rsub|n>|)>+4Var<around*|(|X<rsub|n+1>|)>=5\<sigma\><rsup|2>>

      <math|\<rho\><rsub|Y<rsub|n>,Y<rsub|n+1>>=<dfrac|Cov<around*|(|Y<rsub|n>,Y<rsub|n+1>|)>|<sqrt|Var<around*|(|Y<rsub|n>|)>Var<around*|(|Y<rsub|n+1>|)>>>=<dfrac|2\<sigma\><rsup|2>|5\<sigma\><rsup|2>>=<dfrac|2|5>>
    </enumerate-alpha>

    \;
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|?|../../../.TeXmacs/texts/scratch/no_name_5.tm>>
  </collection>
</references>