<TeXmacs|1.99.4>

<style|generic>

<\body>
  <\enumerate-numeric>
    <item>

    <\enumerate-alpha>
      <item>Let <math|LSP<around*|(|s,t|)>=s<rprime|'>> denote the vertex
      directly connected to <math|s> on the longest simple path from <math|s>
      to <math|t>.

      Let <math|w<around*|(|s,s<rprime|'>|)>> where
      <math|<around*|(|s,s<rprime|'>|)>\<in\>E>, denote the weight put on the
      edge.

      Let <math|W<around*|(|s,t|)>> denote the total weight of the longeest
      simple path from <math|s> to <math|t>.

      Then we have <math|LSP<around*|(|s,t|)>=argmax<rsub|<around*|{|s<rprime|'><around*|\|||\<nobracket\>><around*|(|s,s<rprime|'>|)>\<in\>E|}>><around*|(|w<around*|(|s,s<rprime|'>|)>+W<around*|(|s<rprime|'>,t|)>|)>>

      <math|W<around*|(|s,t|)>=max<rsub|<around*|{|s<rprime|'><around*|\|||\<nobracket\>><around*|(|s,s<rprime|'>|)>\<in\>E|}>><around*|(|w<around*|(|s,s<rprime|'>|)>+W<around*|(|s<rprime|'>,t|)>|)>=w<around*|(|s,LSP<around*|(|s,t|)>|)>+W<around*|(|LSP<around*|(|s,t|)>,t|)>>

      <item>Let <math|V<rsub|s>=<around*|{|v\<in\>V<around*|\||\<exists\>path
      from s to v|\<nobracket\>>|}>>, <math|E<rsub|s>=<around*|{|<around*|(|u,v|)>\<in\>E<around*|\||u,v\<in\>V<rsub|s>|\<nobracket\>>|}>>

      There are at most <math|<around*|\||V<rsub|s>|\|>> subproblems
      <math|W<around*|(|s<rprime|'>,t|)>>,
      <math|LSP<around*|(|s<rprime|'>,t|)>>, where
      <math|s<rprime|'>\<in\>V<rsub|s>>

      Suppose we know whether a vertex is connected with <math|t>, then the
      total number of subproblems is <math|<around*|\||<around*|{|v\<in\>V<rsub|s><around*|\||v
      is connected to t|\<nobracket\>>|}>|\|>>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item>Let <math|s > denote the string we deal with.

      Let <math|W<around*|(|i,j|)>> denote the length of the longest
      palindrome subsequence of the string <math|s<around*|(|i:j|)>>.

      <math|W<around*|(|i,j|)>=<around*|{|<tabular|<tformat|<table|<row|<cell|2+W<around*|(|i+1,j-1|)>>|<cell|if
      s<around*|(|i|)>\<longequal\>s<around*|(|j|)>>>|<row|<cell|max<around*|(|W<around*|(|i+1,j|)>,W<around*|(|i,j-1|)>|)>>|<cell|otherwise>>>>>|\<nobracket\>>
      >

      Let <math|p<around*|(|i,j|)>> denote the corresponding longest
      palindrome subsequence of the string <math|s<around*|(|i:j|)>>.

      <math|p<around*|(|i,j|)>=<around*|{|<tabular|<tformat|<table|<row|<cell|s<around*|(|i|)>p<around*|(|i+1,j-1|)>s<around*|(|j|)>>|<cell|if
      s<around*|(|i|)>\<longequal\>s<around*|(|j|)>>>|<row|<cell|p<around*|(|i+1,j|)>>|<cell|if
      W<around*|(|i+1,j|)>\<gtr\>W<around*|(|i,j-1|)>>>|<row|<cell|p<around*|(|i,j-1|)>>|<cell|if
      W<around*|(|i+1,j|)>\<leqslant\>W<around*|(|i,j-1|)>>>>>>|\<nobracket\>>>

      <item>The subproblems are all <math|W<around*|(|i,j|)>>,
      <math|p<around*|(|i,j|)>> s.t. <math|i\<leqslant\>j>. Therefore, worst
      case we have <math|\<Theta\><around*|(|n<rsup|2>|)>>.
    </enumerate-alpha>

    <item>

    <item>

    <\enumerate-alpha>
      <item>Let <math|l<rsub|1>,l<rsub|2>,\<ldots\>,l<rsub|n>> denote the
      length of strings we are dealing with.

      Let <math|s > denote the string we deal with.

      Let <math|W<around*|(|i,j|)>> denote the minimal cost of printing
      <math|word> <math|i> to <math|j> starting on a new line.

      If <math|s<around*|(|i:n|)>> can be printed on one line, then certainly
      the cost is zero. Otherwise, the minimum cost is the minimum (over
      <math|j>) of the cost of this line <math|s<around*|(|i:j|)>> plus the
      minimum cost of the rest lines <math|s<around*|(|j:n|)>>.

      <\math>
        W<around*|(|i,n|)>=

        <around*|{|<tabular|<tformat|<cwith|1|-1|1|-1|cell-halign|c>|<cwith|1|-1|1|-1|cell-valign|c>|<table|<row|<cell|0
        \ >|<cell|if M-n+i-<big|sum><rsup|n><rsub|k=i>l<rsub|k>\<geqslant\>0>>|<row|<cell|<below|min|M-j+i-<big|sum><rsup|j><rsub|k=i>l<rsub|k>\<geqslant\>0><around*|[|<around*|(|M-j+i-<big|sum><rsup|j><rsub|k=i>l<rsub|k>|)><rsup|3>+W<around*|(|j+1,n|)>|]>>|<cell|otherwise>>>>>|\<nobracket\>>
      </math>

      And we then print the sequence of words accordingly.

      <item>The subproblems are all <math|W<around*|(|i,n|)>>, s.t.
      <math|i\<less\>n>. Therefore, worst case we have
      <math|\<Theta\><around*|(|n|)>>.
    </enumerate-alpha>

    <item>

    <item>

    <\enumerate-alpha>
      <item>Let <math|s > denote the string we deal with.

      Let <math|C<around*|(|N|)>> denote the conviviality of node <math|N>.

      Let <math|W<around*|(|N|)>> denote the maximal conviviality of the
      subtree rooted at node <math|N>.

      If the person represented by node <math|N> is to be selected, then the
      total maximum conviviality is just the sum of this person's
      conviviality and the maximum conviviality starting from one of the
      node's grand children. Otherwise, the total maximum conviviality is the
      maximum conviviality starting from one of the node's children.

      <math|W<around*|(|N|)>=max<around*|(|C<around*|(|N|)>+max<rsub|P\<in\>GrandChildren
      of N><around*|(|W<around*|(|P|)>|)>,max<rsub|P\<in\>Children of
      N><around*|(|W<around*|(|P|)>|)>|)>>

      Note if <math|N> is leaf, then <math|W<around*|(|N|)>=C<around*|(|N|)>>.

      And we then select the nodes accordingly.

      <item>The subproblems are all <math|W<around*|(|N|)>>, where <math|N>
      is any node. Therefore, worst case we have
      <math|\<Theta\><around*|(|<around*|\||Nodes|\|>|)>> subproblems.
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item>Let <math|P<around*|(|w,i|)>> denote the maximum possibility of
      starting from node <math|w>, to achieve sequence
      <math|\<sigma\><rsub|i>,\<sigma\><rsub|i+1>,\<ldots\>,\<sigma\><rsub|n>>

      <math|P<around*|(|w,w|)>=1>\ 

      We denote <math|P<around*|(|w,x|)>=P<around*|(|w,x|)>>, if
      <math|w*x\<in\>E>, the probability put on the edge <math|w*x>.

      The maximum possibility is simply the maximum (over next vertex
      <math|x>) of the product of possibility of edge <math|w*x> and the
      maximum possibility of starting from node <math|x>, to achieve sequence
      <math|\<sigma\><rsub|i+1>,\<sigma\><rsub|i+2>,\<ldots\>,\<sigma\><rsub|n>>.

      <math|P<around*|(|w,i|)>=max<rsub|<around*|{|x<around*|\||w*x\<in\>E|\<nobracket\>>,\<sigma\><around*|(|w,x|)>=\<sigma\><around*|(|i|)>|}>><around*|(|P<around*|(|w,x|)>P<around*|(|x,i+1|)>|)>>

      Note that if <math|w> is a leaf/end vertex, and the sequence has not
      been achieved, then the possibility becomes zero.

      And we select the argmax as the path nodes.

      <item>The subproblems are all <math|P<around*|(|w,i|)>>, where <math|w>
      is a node connected to <math|v<rsub|0>>, and <math|i> is from 1 to
      <math|n>. Though the real size will definitely be smaller, we can
      estimate as <math|\<Theta\><around*|(|<around*|\||V|\|>n|)>>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item>Let <math|M<around*|(|i,j|)>> denote the minimum disruption for
      removing <math|A<around*|(|i,j|)>> and removing pixels on row
      <math|i+1> to <math|m>.

      Then the minimum total disruption is simply the disruption of this
      pixel plus the minimum total disruption starting from the feasible
      pixels on the next row.

      <math|M<around*|(|i,j|)>=<around*|{|<tabular|<tformat|<table|<row|<cell|d<around*|(|i,j|)>>|<cell|if
      i\<longequal\>m>>|<row|<cell|d<around*|(|i,j|)>+max<rsub|k=0,\<pm\>1><around*|(|d<around*|(|i+1,j+k|)>|)>>|<cell|otherwise>>>>>|\<nobracket\>>>

      Note that if <math|j+k> is out of range, then we simply don't consider
      such case.

      And then we select the pixels accordingly.

      <item>The subproblems are all <math|M<around*|(|i,j|)>> where
      <math|i\<leqslant\>m>, <math|j\<leqslant\>n>. Therefore
      <math|\<Theta\><around*|(|mn|)>.>
    </enumerate-alpha>

    <item>

    <\enumerate-alpha>
      <item>Let <math|l<rsub|1>,l<rsub|2>,\<ldots\>,l<rsub|m>> be the break
      points, let <math|l<rsub|0>=0>, <math|l<rsub|m+1>=n>

      Let <math|C<around*|(|i,j|)>> denote the minimum cost of breaking the
      string <math|S<around*|(|l<rsub|i>+1:l<rsub|j>|)>>, which contains the
      break points <math|l<rsub|i+1>,\<ldots\>,l<rsub|j-1>>.

      <math|C<around*|(|i,i+1|)>=0>

      <math|C<around*|(|i,j|)>=l<rsub|j>-l<rsub|i>+min<rsub|k=i+1:j-1><around*|(|C<around*|(|i,k|)>+C<around*|(|k,j|)>|)>>

      And we then determine the order of breaking accordingly.

      <item>The subproblems are <math|C<around*|(|i,j|)>>, where
      <math|0\<leqslant\>i\<less\>j\<leqslant\>m+1>. Therefore, worst case we
      have <math|\<Theta\><around*|(|m<rsup|2>|)>> subproblems.
    </enumerate-alpha>

    <item>

    <item>

    <item>

    <\enumerate-alpha>
      <item>Let <math|p<around*|(|i,j|)>> denote the <math|j<rsup|th>> player
      for the <math|i<rsup|th>> position.

      Let <math|M<around*|(|i,j|)>>, <math|V<around*|(|i,j|)>> denote the
      money, and VORP, respectively, of the <math|j<rsup|th>> player for the
      <math|i<rsup|th>> position.

      Let <math|P<around*|(|i,Y|)>> denote the maximum sum of VORP for
      position <math|i,i+1,\<ldots\>.,N>, with money <math|Y>.

      <math|P<around*|(|i,Y|)>=max<rsub|<around*|{|p<around*|(|i,j|)><around*|\|||\<nobracket\>>Y-M<around*|(|i,j|)>\<geqslant\>0|}>><around*|(|V<around*|(|i,j|)>+P<around*|(|i+1,Y-M<around*|(|i,j|)>|)>|)>>

      We then select the argmax as the player.

      <item>One possible estimation is <math|\<Theta\><around*|(|N*X|)>>,
      since the subproblems <math|P<around*|(|i,Y|)>> ranges over <math|i>
      and <math|Y>, where they take values from <math|1> to <math|N>, and
      <math|1> to <math|X>.

      We acknowledge that such estimation may be overestimation, since it's
      unlikely that the subproblems actually go over each value of <math|X>
      (even if we normalize by 10000). We could also estimate the number of
      possible values of <math|X> with the number of all possible
      combinations of players on positions, which is <math|P<rsup|N>>;
      however, considering the magnitude, there is expected to be significant
      overlapping, which makes <math|P<rsup|N>> an even worse estimation of
      the possible values of <math|X>.\ 

      Therefore, in conclusion, <math|\<Theta\><around*|(|N*X|)>>.
    </enumerate-alpha>

    \;
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>