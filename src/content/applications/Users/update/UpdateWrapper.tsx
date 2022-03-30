import { useEffect, useState } from 'react';
import { useParams } from 'react-router';
import { Users } from 'src/models/users';
import { findOne } from 'src/services/users';
import UpdateUserForm from './UpdateUserForm';

function UpdateWrapper() {
  const params = useParams();
  const [user, setUser] = useState<Users>();
  useEffect(() => {
    const fetchClient = async () => {
      const client = await findOne(params.id);
      setUser(client);
    };
    fetchClient();
  }, [setUser, params]);

  return (
    <>
      <UpdateUserForm {...user} />
    </>
  );
}

export default UpdateWrapper;
