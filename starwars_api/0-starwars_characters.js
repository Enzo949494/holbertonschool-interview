#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Failed to fetch movie: ${response.statusCode}`);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  printCharacters(characters, 0);
});

function printCharacters (characterUrls, index) {
  if (index >= characterUrls.length) {
    return;
  }

  request(characterUrls[index], (error, response, body) => {
    if (error) {
      console.error(error);
      return;
    }

    if (response.statusCode === 200) {
      const characterData = JSON.parse(body);
      console.log(characterData.name);
    }

    printCharacters(characterUrls, index + 1);
  });
}
