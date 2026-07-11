grade(Marks,'A'):-     Marks >= 80,     !.
grade(Marks,'B'):-     Marks >= 60,     !.
grade(Marks,'C'):-     Marks >= 40,     !.
grade(_,'F').
