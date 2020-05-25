
SELECT DISTINCT linked_movie_id, movie_id, (CASE WHEN link_type_id=1 THEN "secuela" WHEN link_type_id=2 THEN "precuela" else "remake" end) as tipo
					FROM movie_link INNER JOIN title ON title.kind_id=1
					                                  AND ((title.id=movie_id AND linked_movie_id in(select id from title where kind_id= 1))
                                                OR title.id=linked_movie_id AND movie_id in(select id from title where kind_id=1))
					                                  AND(link_type_id= 1 OR link_type_id = 2 OR link_type_id=3);
