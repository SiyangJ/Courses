<TeXmacs|1.99.4>

<style|generic>

<\body>
  <doc-data|<doc-title|STOR 435 Homework 23>|<doc-author|<author-data|<author-name|Siyang
  Jing>>>>

  <\enumerate-numeric>
    <item>First we notice that <math|X> and <math|Y> are apparently
    independent.

    <math|\<bbb-E\><around*|(|Z|)>=\<bbb-E\><around*|(|X|)>\<bbb-E\><around*|(|Y|)>=3.5<rsup|2>=<dfrac|49|4>>

    <math|Var<around*|(|Z|)>=\<bbb-E\><around*|(|Z<rsup|2>|)>-\<bbb-E\><around*|(|Z|)><rsup|2>=\<bbb-E\><around*|(|X<rsup|2>Y<rsup|2>|)>=\<bbb-E\><around*|(|X<rsup|2>|)>\<bbb-E\><around*|(|Y<rsup|2>|)>-\<bbb-E\><around*|(|Z|)><rsup|2>=<dfrac|91|6><dfrac|91|6>-<around*|(|<dfrac|49|4>|)><rsup|2>=<dfrac|11515|144>>

    <item>We notice that for any independent variables <math|X>, <math|Y>,
    <math|Cov<around*|(|X,Y|)>=\<bbb-E\><around*|(|X<rsup|>Y|)>-\<bbb-E\><around*|(|X|)>\<bbb-E\><around*|(|Y|)>=0>

    <math|Var<around*|(|X-Y|)>=Var<around*|(|X|)>+Var<around*|(|Y|)>-2Cov<around*|(|X,Y|)>=<dfrac|1|12>+<dfrac|1|12>=<dfrac|1|6>>

    <item>This question seems suitable for indicator variables.\ 

    Reason: 1. Number of events; 2. Only want expectation.

    Let <math|A<rsub|i>=>{The <math|i,i+1,i+2> tossing are
    <math|H<rsup|>T<rsup|>H>}. Let <math|X=<big|sum><rsup|i=48><rsub|i=1>I<rsub|A<rsub|i>>>.

    <math|\<bbb-E\><around*|(|X|)>=<big|sum><rsup|i=48><rsub|i=1>\<bbb-E\><around*|(|I<rsub|A<rsub|i>>|)>=48\<times\><dfrac|1|8>=6>

    <item>This question is suitable for indicator variables, since the
    linearity of <math|\<bbb-E\>> is regardless of dependence or independence
    between random variables.

    Let <math|A<rsub|i>=>{Ruoyu got the <math|i>th sort of drink at least
    once}. We have <math|X=<big|sum><rsup|i=10><rsub|i=1>I<rsub|A<rsub|i>>>.

    <math|Pr<around*|(|A<rsub|i>|)>=1-<around*|(|<dfrac|9|10>|)><rsup|20>>

    <math|\<bbb-E\><around*|(|X|)>=<big|sum><rsup|i=10><rsub|i=1>\<bbb-E\><around*|(|I<rsub|A<rsub|i>>|)>=10\<times\><around*|(|1-<around*|(|<dfrac|9|10>|)><rsup|20>|)>\<approx\>8.7842>

    <item><math|\<bbb-E\><around*|(|X|)>=<big|int><rsup|\<infty\>><rsub|0><big|int><rsup|x><rsub|0>x<dfrac|2e<rsup|-2x>|x>d<rsup|>y<rsup|>d<rsup|>x=<big|int><rsup|\<infty\>><rsub|0>x2e<rsup|-2x>d<rsup|>x=<dfrac|1|2>>,
    we can see that <math|X> is an exponential distribution.

    <math|\<bbb-E\><around*|(|Y|)>=<big|int><rsup|\<infty\>><rsub|0><big|int><rsup|x><rsub|0>y<dfrac|2e<rsup|-2x>|x>d<rsup|>y<rsup|>d<rsup|>x=<big|int><rsup|\<infty\>><rsub|0>x<rsup|>e<rsup|-2x>d<rsup|>x=<dfrac|1|4>>

    <math|\<bbb-E\><around*|(|X<rsup|>Y|)>=<big|int><rsup|\<infty\>><rsub|0><big|int><rsup|x><rsub|0>x<rsup|>y<dfrac|2e<rsup|-2x>|x>d<rsup|>y<rsup|>d<rsup|>x=<big|int><rsup|\<infty\>><rsub|0>x<rsup|2><rsup|>e<rsup|-2x>d<rsup|>x=<dfrac|1|4>>

    <math|Cov<around*|(|X,Y|)>=<dfrac|1|8>>

    <item><math|\<bbb-E\><around*|(|3X+4Y-5|)>=3\<bbb-E\><around*|(|X|)>+4\<bbb-E\><around*|(|Y|)>-5=6>

    <math|Var<around*|(|3X+4Y-5|)>=3<rsup|2>Var<around*|(|X|)>+4<rsup|2>Var<around*|(|Y|)>+2\<times\>3\<times\>4Cov<around*|(|X,Y|)>=43>
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>