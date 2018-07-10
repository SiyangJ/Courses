<TeXmacs|1.99.4>

<style|generic>

<\body>
  <\math>
    <big|sum><rsup|N><rsub|k=1>sin<around*|(|j<rsup|>k<frac|\<pi\>|N+1>|)>sin<around*|(|l<rsup|>k<frac|\<pi\>|N+1>|)>=<big|sum><rsup|N><rsub|k=1><frac|1|2><around*|(|e<rsup|i<rsup|>j<rsup|>k<frac|\<pi\>|N+1>>-e<rsup|-j<rsup|>k<frac|\<pi\>|N+1>>|)><frac|1|2><around*|(|e<rsup|l<rsup|>k<frac|\<pi\>|N+1>>-e<rsup|-l<rsup|>k<frac|\<pi\>|N+1>>|)>
  </math>

  <math|=<big|sum><rsup|N><rsub|k=1><frac|1|4><around*|(|e<rsup|i<around*|(|j+l|)>k<frac|\<pi\>|N+1>>+e<rsup|-i<around*|(|j+l|)>k<frac|\<pi\>|N+1>>-e<rsup|i<around*|(|j-l|)>k<frac|\<pi\>|N+1>>-e<rsup|-i<around*|(|j-l|)>k<frac|\<pi\>|N+1>>|)>>

  <math|=<big|sum><rsup|N><rsub|k=1>cos<around*|(|<around*|(|j+l|)><rsup|>k<frac|\<pi\>|N+1>|)>-cos<around*|(|<around*|(|j-l|)><rsup|>k<frac|\<pi\>|N+1>|)>>

  Let <math|\<mu\>=j+l>, <math|\<nu\>=j-l>, they are both odd/even

  <math|=<big|sum><rsup|<around*|\<lfloor\>|N/2|\<rfloor\>>><rsub|k=1>cos<around*|(|\<mu\><rsup|>k<frac|\<pi\>|N+1>|)>+cos<around*|(|\<mu\><around*|(|N+1-k|)><frac|\<pi\>|N+1>|)>-cos<around*|(|\<nu\><around*|(|N+1-k|)><frac|\<pi\>|N+1>|)>-cos<around*|(|\<nu\>k<frac|\<pi\>|N+1>|)>>

  <math|=<big|sum><rsup|<around*|\<lfloor\>|N/2|\<rfloor\>>><rsub|k=1>cos<around*|(|\<mu\><rsup|>k<frac|\<pi\>|N+1>|)>+cos<around*|(|\<mu\>\<pi\>-\<mu\>k<frac|\<pi\>|N+1>|)>-cos<around*|(|\<nu\>\<pi\>-\<nu\>k<frac|\<pi\>|N+1>|)>-cos<around*|(|\<nu\>k<frac|\<pi\>|N+1>|)>>

  <math|=<around*|{|<tabular|<tformat|<cwith|1|1|1|1|cell-halign|c>|<cwith|2|2|1|1|cell-halign|c>|<table|<row|<cell|<big|sum><rsup|<around*|\<lfloor\>|N/2|\<rfloor\>>><rsub|k=1>cos<around*|(|\<mu\><rsup|>k<frac|\<pi\>|N+1>|)>-cos<around*|(|\<mu\>k<frac|\<pi\>|N+1>|)>+cos<around*|(|\<nu\>k<frac|\<pi\>|N+1>|)>-cos<around*|(|\<nu\>k<frac|\<pi\>|N+1>|)>,for
  \<nu\>,\<mu\> odd>>|<row|<cell|>>>>>|\<nobracket\>>>

  <math|=<big|sum><rsup|N><rsub|k=1>sin<around*|(|j<rsup|>k<frac|\<pi\>|N+1>|)>sin<around*|(|l<rsup|>k<frac|\<pi\>|N+1>|)>>

  \;

  <math|=<frac|1|4><big|sum><rsup|N><rsub|k=1><around*|(|e<rsup|<around*|(|j+l|)>k<frac|\<pi\>|N+1>>+e<rsup|-<around*|(|j+l|)>k<frac|\<pi\>|N+1>>-e<rsup|<around*|(|j-l|)>k<frac|\<pi\>|N+1>>-e<rsup|-<around*|(|j-l|)>k<frac|\<pi\>|N+1>>|)>>

  <math|=<frac|1|4><around*|(|e<rsup|i<around*|(|j+l|)><frac|\<pi\>|N+1>><frac|1-e<rsup|i<around*|(|j+l|)>N<frac|\<pi\>|N+1>>|1-e<rsup|i<around*|(|j+l|)><frac|\<pi\>|N+1>>>|)><big|sum><rsup|N><rsub|k=1><around*|(|e<rsup|<around*|(|j+l|)>k<frac|\<pi\>|N+1>>+e<rsup|-<around*|(|j+l|)>k<frac|\<pi\>|N+1>>-e<rsup|<around*|(|j-l|)>k<frac|\<pi\>|N+1>>-e<rsup|-<around*|(|j-l|)>k<frac|\<pi\>|N+1>>|)>>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>