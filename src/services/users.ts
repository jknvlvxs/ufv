import { Users } from 'src/models/users';
import api from './api';

export const findAll = async () => {
  const response = await api.get('/users');
  return response.data as Users[];
};

export const findOne = async (id) => {
  const response = await api.get(`/users/${id}`);
  return response.data as Users;
};

export const create = async (data) => {
  const response = await api.post('/users', data);
  return response.data as Users;
};

export const update = async (id, data) => {
  try {
    const response = await api.patch(`/users/${id}`, data);
    return response;
  } catch (error) {
    return error;
  }
};

export const remove = async (id) => {
  const response = await api.delete(`/users/${id}`);
  return response.data as Users;
};
