<TeXmacs|1.99.4>

<style|generic>

<\body>
  5.2.3

  <math|r=<big|sum><rsup|6><rsub|i=1>i*I<around*|(|r=i|)>>

  <math|\<bbb-E\><around*|(|r|)>=\<bbb-E\><around*|(|<big|sum><rsup|6><rsub|i=1>i*I<around*|(|r=i|)>|)>=<big|sum><rsup|6><rsub|i=1>i\<bbb-E\><around*|(|I<around*|(|r=i|)>|)>=><math|<big|sum><rsup|6><rsub|i=1>i*P<around*|(|r=i|)>=3.5>

  <math|\<bbb-E\><around*|(|<big|sum><rsup|n><rsub|j=1>r<rsub|j>|)>=<big|sum><rsup|n><rsub|j=1>\<bbb-E\><around*|(|r<rsub|j>|)>=n\<bbb-E\><around*|(|r|)>=3.5n>

  \;

  5.2.4

  <math|X<rsub|i>=1>, if person <math|i> get back his/her hat, <math|0>
  otherwise.

  <math|X=<big|sum><rsup|n><rsub|i=1>X<rsub|i>>, the number of people that
  get back hat.

  <math|\<bbb-E\><around*|(|X|)>=<big|sum><rsup|n><rsub|i=1>\<bbb-E\>X<rsub|i>=<big|sum><rsup|n><rsub|i=1>P<around*|(|person
  i get back hat|)>=<big|sum><rsup|n><rsub|i=1>1/n=1>

  Note: Expectation is linear even when random variables are dependent.

  \;

  5.2.5

  <math|X<rsub|i,j>=I<around*|(|<around*|(|i.j|)> is an inversion|)>>

  <math|X=<big|sum><rsub|i\<less\>j>X<rsub|i,j>>, the number of inversions

  <math|\<bbb-E\><around*|(|X|)>=<big|sum><rsub|i\<less\>j>\<bbb-E\>X<rsub|i,j>=<big|sum><rsub|i\<less\>j>P<around*|(|<around*|(|i.j|)>
  is an inversion|)>=<big|sum><rsub|i\<less\>j>1/2=1/2\<times\><around*|(|n<rsup|2>-n|)>/2>

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>