# elo-rating-demo


$rating' = rating + K(S_A-E_A)$

当K为比赛时取8，补题时取4，K越小本次排名对成绩的影响越小
$$
E_{AB}' = 
\left\{
\begin{split}
E_{AB}+\frac1{1+10^{({rating}_B-{rating}_A)/400}}.\\
\end{split}
\right.
$$

表示A与B相比期望获胜概率
$$
S_{AB}' = 
\left\{
\begin{split}
S_{AB} + 1 & \textrm{如果A战胜了B}\\
S_{AB} + 0.5  & \textrm{如果AB打平}\\
S_{AB} & \textrm{如果A输给B}\\
\end{split}
\right.
$$
表示A与B相比实际获胜情况

对于一场比赛
 $$S_A = \sum_{i\in\textrm{比赛}，i!=A}S_{Ai}$$
 $$E_A = \sum_{i\in\textrm{比赛}，i!=A}E_{Ai}$$
