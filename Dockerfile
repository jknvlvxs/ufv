FROM node:16-alpine3.15

WORKDIR /app

CMD [ -d "node_modules" ] && npm start || npm ci && npm start