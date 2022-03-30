import { Client } from 'src/models/client';
import api from './api';

export const findAll = async () => {
  const response = await api.get('/client');
  return response.data as Client[];
};

export const findSearch = async (search) => {
  const response = await api.get('/client', { params: { search: search } });
  return response.data as Client[];
};

export const findOne = async (id) => {
  const response = await api.get(`/client/${id}`);
  return response.data as Client;
};

export const create = async (data) => {
  const response = await api.post('/client', data, {
    headers: { 'Content-Type': 'multipart/form-data' },
  });
  return response.data as Client;
};

export const update = async (id, data) => {
  try {
    const response = await api.patch(`/client/${id}`, data, {
      headers: { 'Content-Type': 'multipart/form-data' },
    });
    return response;
  } catch (error) {
    return error;
  }
};

export const remove = async (id) => {
  const response = await api.delete(`/client/${id}`);
  return response.data as Client;
};

export const download = async (fileName) => {
  const response = await api.get(`/client/download/${fileName}`, {
    responseType: 'arraybuffer',
  });

  return response.data;
};
