#docker for express app
#https://nodejs.org/de/docs/guides/nodejs-docker-webapp/

#first, I need to type  `npm install` in the app

FROM node:10

WORKDIR /usr/src/app

COPY /app/package*.json ./

RUN npm install

COPY /app/ ./

EXPOSE 8080

CMD [ "node", "server.js" ]

#docker run -p 49160:8080 -d bo04/node-web-app
#check url (http://192.168.99.100:49160)

