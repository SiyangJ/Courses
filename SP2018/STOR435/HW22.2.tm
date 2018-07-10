<TeXmacs|1.99.4>

<style|generic>

<\body>
  <doc-data|<doc-title|STOR 435 Homework 22>|<doc-author|<\author-data|<author-name|Siyang
  Jing>>
    \;
  </author-data>>>

  \;

  <\enumerate-numeric>
    <item><math|Y<around*|\|||\<nobracket\>>X=80\<sim\><with|math-font|cal|N><around*|(|\<mu\>=75+0.8\<times\><dfrac|16|10><around*|(|80-85|)>,\<sigma\>=<sqrt|1-0.8<rsup|2>>\<times\>16|)>\<sim\><with|math-font|cal|N><around*|(|\<mu\>=68.6,\<sigma\>=9.6|)>>

    <math|P<around*|(|Y\<gtr\>80<around*|\|||\<nobracket\>>X=80|)>=1-F<rsub|Y<around*|\|||\<nobracket\>>X><around*|(|80<around*|\|||\<nobracket\>>80|)>=1-\<Phi\><around*|(|<dfrac|80-68.6|9.6>|)>\<approx\>0.1170>
    (table), 0.1175 (exact)

    <item>

    <\enumerate-alpha>
      <item><math|f<rsub|U,V><around*|(|u,v|)>=f<rsub|X,Y><around*|(|u<rsup|>v,v|)><around*|\||det<around*|(|<tabular|<tformat|<cwith|1|-1|1|-1|cell-halign|c>|<table|<row|<cell|v>|<cell|u>>|<row|<cell|0>|<cell|1>>>>>|)>|\|>=f<rsub|X><around*|(|u<rsup|>v|)>f<rsub|Y><around*|(|v|)>v=\<alpha\>\<beta\>v<rsup|>e<rsup|-\<alpha\>u<rsup|>v-\<beta\>v>>

      <math|U\<in\><around*|[|0,\<infty\>|)>>,
      <math|V\<in\><around*|(|0,\<infty\>|)>>

      // Question: Can <math|V=0>?

      // If <math|V=0>, then <math|U=X/0> is not really well-defined

      // If <math|V=0>, then <math|f<rsub|U,V><around*|(|u,v|)>=0>.

      // From this point of view, <math|V> cannot equal 0

      // However, <math|V=Y> means <math|V> have the same domain as <math|Y>,
      which includes 0

      // Further question: We have assumed <math|g> is invertible, but here
      it's probably not.

      // Consider a simpler case, <math|W\<assign\>1/Y>, what can we say
      about <math|W>?

      // However, for <math|U>, <math|0/0> could be defined maybe? As a
      limit?

      // Need a more mathematically rigorous definition for things like
      <math|X/Y>

      // In fact, we haven't seen any mathematically rigorous definition for
      anything.

      <item><math|f<rsub|V><around*|(|v|)>=f<rsub|Y><around*|(|v|)>=\<beta\>e<rsup|-\<beta\>v>>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|<dfrac|\<partial\><around*|(|x,y|)>|\<partial\><around*|(|R,\<theta\>|)>>=det<around*|(|<tabular|<tformat|<cwith|1|-1|1|-1|cell-halign|c>|<table|<row|<cell|cos<around*|(|\<theta\>|)>>|<cell|sin<around*|(|\<theta\>|)>>>|<row|<cell|-R*sin<around*|(|\<theta\>|)>>|<cell|R*cos<around*|(|\<theta\>|)>>>>>>|)>=R>

      <math|f<rsub|R,\<theta\>><around*|(|R,\<theta\>|)>=f<rsub|X,Y><around*|(|x,y|)>R=f<rsub|X><around*|(|x|)>f<rsub|Y><around*|(|y|)>R=<around*|(|2\<pi\>|)><rsup|-1>e<rsup|-<dfrac|1|2><around*|(|x<rsup|2>+y<rsup|2>|)>>R=<around*|(|2\<pi\>|)><rsup|-1>e<rsup|-<dfrac|1|2>R<rsup|2>>R>

      <item><math|f<rsub|\<theta\>><around*|(|\<theta\>|)>=<big|int><rsup|\<infty\>><rsub|0>f<rsub|R,\<theta\>><around*|(|R,\<theta\>|)>d<rsup|>R=<around*|(|2\<pi\>|)><rsup|-1>>

      <math|\<theta\>> is a uniform distribution on
      <math|<around*|[|0,2\<pi\>|]>>,

      which confirms the isometric symmetry of Gaussian.
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item><math|<dfrac|\<partial\><around*|(|x<rsub|1>,x<rsub|2>|)>|\<partial\><around*|(|y<rsub|1>,y<rsub|2>|)>>=det<around*|(|<tabular|<tformat|<cwith|1|-1|1|-1|cell-halign|c>|<table|<row|<cell|1>|<cell|1>>|<row|<cell|1>|<cell|-1>>>>>|)><rsup|-1>=-1/2>

      <math|f<rsub|Y<rsub|1>,Y<rsub|2>><around*|(|y<rsub|1>,y<rsub|2>|)>=f<rsub|X<rsub|1>,X<rsub|2>><around*|(|x<rsub|1>,x<rsub|2>|)>/2=<around*|(|2\<pi\>|)><rsup|-1>e<rsup|-<dfrac|1|2><around*|(|x<rsub|1><rsup|2>+x<rsub|2><rsup|2>|)>>/2=<dfrac|1|<sqrt|2\<pi\>><sqrt|2>>e<rsup|-<dfrac|1|2><around*|(|<dfrac|y<rsub|1>|<sqrt|2>>|)><rsup|2>><dfrac|1|<sqrt|2\<pi\>><sqrt|2>>e<rsup|-<dfrac|1|2><around*|(|<dfrac|y<rsub|2>|<sqrt|2>>|)><rsup|2>><rsup|>>

      <item>We identify this as the product of two normal pdf's, which means
      <math|Y<rsub|1>> and <math|Y<rsub|2>> are separable, and

      <math|Y<rsub|1>\<sim\>Y<rsub|2>\<sim\><with|math-font|cal|N><around*|(|\<mu\>=0,\<sigma\><rsup|2>=2|)>>
    </enumerate-alpha>
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|?|HW22.tm>>
    <associate|auto-2|<tuple|2|?|HW22.tm>>
    <associate|auto-3|<tuple|3|?|HW22.tm>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <with|par-left|<quote|4tab>|Notes on Bivariate Normal Distribution
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.15fn>>

      <with|par-left|<quote|4tab>|Notes on Joint Probability and Mappings
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-2><vspace|0.15fn>>

      <with|par-left|<quote|4tab>|Homework
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-3><vspace|0.15fn>>
    </associate>
  </collection>
</auxiliary>