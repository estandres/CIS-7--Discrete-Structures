P -> Q <=>   Q'->P'
P' v Q <=>   Q'->P'   (Implication)
Q v P' <=>   Q'->P'   (Commutative)
Q v P' <=>   Q'' v P' (Implication)
Q v P' <=>   Q v P'   (Double Negation)


(P -> R) ^ (Q -> R) <=> (P v Q) -> R
(P' v R) ^ (Q' v R) <=> (P v Q) -> R                       (Implication)
(P' ^ (Q' v R)) v (R ^ (Q' v R))  <=> (P v Q) -> R         (Distributive)
(P' ^ Q') v (P' ^ R) v (R ^ Q') v (R ^ R) <=> (P v Q) -> R (Distributive)
(P' ^ Q') v (P' ^ R) v (R ^ Q') v R <=> (P v Q) -> R
(P' ^ Q') v (P' ^ R) v R <=> (P v Q) -> R                  (Absorption)
(P' ^ Q') v R   <=> (P v Q) -> R                           (Absorption)
(P' ^ Q')' -> R <=> (P v Q) -> R                           (Implication) (De Morgan's)
(P v Q) -> R    <=> (P v Q) -> R                           (Double Negation)
