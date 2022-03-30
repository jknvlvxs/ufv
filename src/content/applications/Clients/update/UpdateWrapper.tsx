import { useEffect, useState } from 'react';
import { useParams } from 'react-router';
import { Client } from 'src/models/client';
import { findOne } from 'src/services/client';
import UpdateClientForm from './UpdateClientForm';

function UpdateWrapper() {
  const params = useParams();
  const [client, setClient] = useState<Client>();
  useEffect(() => {
    const fetchClient = async () => {
      const client = await findOne(params.id);
      setClient(client);
    };
    fetchClient();
  }, [setClient, params]);

  return (
    <>
      <UpdateClientForm {...client} />
    </>
  );
}

export default UpdateWrapper;
