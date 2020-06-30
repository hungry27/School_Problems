select distinct name
from people join stars on stars.person_id = people.id
where name != "Kevin Bacon"
and movie_id IN (
    select movie_id
    from people join stars on stars.person_id = people.id
    where name = "Kevin Bacon" and birth = 1958
)