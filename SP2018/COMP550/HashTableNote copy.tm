<TeXmacs|1.99.4>

<style|generic>

<\body>
  Dictionaries: Insert, Search, Delete

  Only the above operations are supported.

  \;

  Hash Table is a good structure to implement dictionaries.

  \;

  Direct-Address tables

  <math|h<around*|(|k|)>=k>

  When <math|<around*|\||U|\|>> is not too large

  \;

  Hash Tables

  How to handle collisions?

  Make <math|h> appear to be \Prandom\Q

  \;

  <section|Chaining>

  Use a linked-list at every spot.

  Note: possibly a better way to do this? Binary Tree?

  <subsection|Insert>

  <math|O<around*|(|1|)>>

  <subsection|Search>

  Load factor <math|\<alpha\>\<assign\>n/m>, the average number of items in a
  chain.

  <paragraph|Simple Uniform Hashing:>Any given element is equally likely to
  hash into any of the <math|m> slots.

  <paragraph|Worst Case:><math|\<Theta\><around*|(|n|)>>, all hashed to the
  same place

  <paragraph|Average Case:>simple uniform hashing: Any given element is
  equally likely to hash into any of the <math|m> slots

  <subparagraph|Unsuccessful Search:>We have to seach to the end of the
  linked list, so <math|\<bbb-E\><around*|(|#elements searched in the
  list|)>=\<alpha\>>

  Therefore, <math|\<Theta\><around*|(|1+\<alpha\>|)>>, which means
  <math|\<Theta\><around*|(|1|)>> computation of hasing function, and
  <math|\<Theta\><around*|(|\<alpha\>|)>> search in the list.

  <subparagraph|Successful Search:>Also <math|\<Theta\><around*|(|1+\<alpha\>|)>>,
  proof below: //TODO: need details

  <math|\<bbb-E\><around*|(|#elements searched in the
  list|)>=\<bbb-E\><around*|(|1+#elements inserted after
  x|)>=1+<frac|\<alpha\>|2>-<frac|\<alpha\>|2n>=\<Theta\><around*|(|1+\<alpha\>|)>>

  \;

  This means if <math|n=O<around*|(|m|)>>, i.e. the number of elements in the
  table is proportional to the number of slots, then
  <math|\<alpha\>=O<around*|(|1|)>>, then the search, unsuccessful or
  successful, takes <math|O<around*|(|1|)>>.

  <subsection|Delete (given node, not key)>

  <math|O<around*|(|1|)>>, if doubly linked.

  <math|O<around*|(|1+\<alpha\>|)>>, the same as a search, if singly linked,
  or given key.

  <subsection|Exercises:>

  <subparagraph|11.2-1>

  Let <math|k<rsub|i>> be the keys. We define the indicator variable
  <math|X<rsub|i<rsup|>j>> to indicate <math|h<around*|(|k<rsub|i>|)>=h<around*|(|k<rsub|j>|)>>.

  Under s.u.h assumption, since the hash values of <math|k<rsub|i>> and
  <math|k<rsub|j>> are independent, <math|\<bbb-E\><around*|(|X<rsub|i<rsup|>j>|)>=1/m>

  <math|\<bbb-E\><around*|(|#collisions|)>=\<bbb-E\><around*|(|<big|sum><rsub|i\<less\>j>X<rsub|i<rsup|>j>|)>=<big|sum><rsub|i\<less\>j>\<bbb-E\><around*|(|X<rsub|i<rsup|>j>|)>=n<around*|(|n-1|)>/2m=\<alpha\><around*|(|n-1|)>/2>

  \;

  <section|Hash Functions>

  Good: satisfies assumption of s.u.h.

  Fact: we do not know the distribution.

  \;

  One approach: The hash value independent of any patterns in the data.

  Example: Division method, i.e., mod a prime number, if the prime number is
  unrelated to the patterns.

  //TODO: need detail of what unrelated means.

  \;

  Good is not enough

  Example: We want keys that are \Pclose\Q to hash far apart.

  \;

  Interpreting keys as natural numbers

  Due to the discreteness of computer science, we can usually map the keys to
  <math|\<bbb-N\>>

  Example: strings as radix-128 numbers. <math|c\<mapsto\>ASC\<bbb-I\><around*|(|c|)>>

  \;

  <subsection|The division method>

  <math|h<around*|(|k|)>=k mod m>.

  We usually choose <math|m> to be prime and not near <math|2<rsup|p>>

  \;

  <subsection|The multiplication method>

  <math|h<around*|(|k|)>=<around*|\<lfloor\>|m<around*|(|k*A
  mod*1|)>|\<rfloor\>>>, <math|A\<in\><around*|(|0,1|)>>

  The value of <math|m> is not critical in this setting, and we usually
  choose it to be power of 2 <math|m=2<rsup|p>>

  Then we restrict <math|A> to <math|s\<times\>2<rsup|-w>>.

  \;

  <subsection|Universal Hashing>

  In an adversary setting,

  Choose the hash function \Prandomly\Q and \Pindependent\Q of the keys that
  are actually going to be stored

  \;

  At the beginning of the execution, we select the hash function at random
  from a class of functions.

  \;

  Let <math|\<cal-H\>> be the set of hash functions. \Puniversal\Q:

  <math|\<forall\>k,l\<in\>U,<around*|\||<around*|{|h\<in\>\<cal-H\>\<wedge\>h<around*|(|k|)>=h<around*|(|l|)>|)>|\|>\<leqslant\><around*|\||\<cal-H\>|\|>/m>

  \;

  <paragraph|Theorem 11.3><math|h\<in\>\<cal-H\>>, <math|n> keys, size
  <math|m>, chaining. If <math|k> is not in the table, then the expectation
  over choices of <math|h>, <math|\<bbb-E\><around*|(|n<rsub|h<around*|(|k|)>>|)>\<leqslant\>\<alpha\>=n/m>,
  if in the table, then <math|\<bbb-E\><around*|(|n<rsub|h<around*|(|k|)>>|)>\<leqslant\>1+\<alpha\>>

  <paragraph|Proof:>

  \;

  \;

  \;

  \;

  \;

  \;

  \;

  \;

  \;

  \;

  \;

  \;

  \;

  \;

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
    <associate|auto-10|<tuple|1.4|?>>
    <associate|auto-11|<tuple|3.3|?>>
    <associate|auto-12|<tuple|2|?>>
    <associate|auto-13|<tuple|2.1|?>>
    <associate|auto-14|<tuple|2.2|?>>
    <associate|auto-15|<tuple|2.3|?>>
    <associate|auto-16|<tuple|4|?>>
    <associate|auto-17|<tuple|5|?>>
    <associate|auto-2|<tuple|1.1|?>>
    <associate|auto-3|<tuple|1.2|?>>
    <associate|auto-4|<tuple|1|?>>
    <associate|auto-5|<tuple|2|?>>
    <associate|auto-6|<tuple|3|?>>
    <associate|auto-7|<tuple|3.1|?>>
    <associate|auto-8|<tuple|3.2|?>>
    <associate|auto-9|<tuple|1.3|?>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|1<space|2spc>Chaining>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.5fn>

      <with|par-left|<quote|1tab>|1.1<space|2spc>Insert
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-2>>

      <with|par-left|<quote|1tab>|1.2<space|2spc>Search
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-3>>

      <with|par-left|<quote|4tab>|Worst Case:
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-4><vspace|0.15fn>>

      <with|par-left|<quote|4tab>|Average Case:
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-5><vspace|0.15fn>>

      Unsuccessful Search: <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-6><vspace|0.15fn>

      Successful Search: <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-7><vspace|0.15fn>

      <with|par-left|<quote|1tab>|1.3<space|2spc>Delete (given node, not key)
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-8>>
    </associate>
  </collection>
</auxiliary>