select name
from people join directors on people.id = directors.person_id
join movies on movies.id = directors.movie_id
join ratings on movies.id = ratings.movie_id
where rating >= 9.0