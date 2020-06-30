select AVG(rating)
from ratings join movies On movies.id = ratings.movie_id
where year = 2012