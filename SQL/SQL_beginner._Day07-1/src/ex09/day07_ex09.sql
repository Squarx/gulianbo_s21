SELECT
  p.address AS address,
  ROUND(MAX(age::numeric) - (MIN(age::numeric) / MAX(age::numeric)), 2) AS formula,
  ROUND(AVG(age), 2) AS average,
  CASE
    WHEN ROUND(MAX(age::numeric) - (MIN(age::numeric) / MAX(age::numeric)), 2) > ROUND(AVG(age), 2) THEN true
    ELSE false
  END AS comparison
FROM
  person p
GROUP BY
  p.address
ORDER BY
  p.address;