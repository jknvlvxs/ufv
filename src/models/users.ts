export type UsersRoles = 'admin' | 'user';

export interface Users {
  id: string;
  name: string;
  email: string;
  role: UsersRoles;
  password: string;
  confirmPassword: string;
}
