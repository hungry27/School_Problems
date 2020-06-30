select title
from movies join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where name = "Johnny Depp" 
and movie_id in(select movie_id from people join stars on stars.person_id = people.id where name = "Helena Bonham Carter")