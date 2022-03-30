import { lazy, Suspense } from 'react';
import { PartialRouteObject } from 'react-router';
import { Navigate } from 'react-router-dom';
import SuspenseLoader from 'src/components/SuspenseLoader';
import BaseLayout from 'src/layouts/BaseLayout';
import SidebarLayout from 'src/layouts/SidebarLayout';

const Loader = (Component) => (props) =>
  (
    <Suspense fallback={<SuspenseLoader />}>
      <Component {...props} />
    </Suspense>
  );

// Dashboards

const Home = Loader(lazy(() => import('src/content/dashboards/Home')));

// Applications

const Clients = Loader(lazy(() => import('src/content/applications/Clients')));
const CreateClient = Loader(
  lazy(() => import('src/content/applications/Clients/create'))
);
const ViewClient = Loader(
  lazy(() => import('src/content/applications/Clients/view'))
);
const UpdateClient = Loader(
  lazy(() => import('src/content/applications/Clients/update'))
);
const Contracts = Loader(
  lazy(() => import('src/content/applications/Contracts'))
);

const Users = Loader(lazy(() => import('src/content/applications/Users')));
const CreateUser = Loader(
  lazy(() => import('src/content/applications/Users/create'))
);
const UpdateUser = Loader(
  lazy(() => import('src/content/applications/Users/update'))
);

// Status

const Status404 = Loader(
  lazy(() => import('src/content/pages/Status/Status404'))
);
const Status500 = Loader(
  lazy(() => import('src/content/pages/Status/Status500'))
);
const StatusComingSoon = Loader(
  lazy(() => import('src/content/pages/Status/ComingSoon'))
);
const StatusMaintenance = Loader(
  lazy(() => import('src/content/pages/Status/Maintenance'))
);
const routes = (admin: boolean) =>
  [
    {
      path: '',
      element: <BaseLayout />,
      children: [
        {
          path: '/',
          element: <Navigate to="/management/clients" replace />,
        },
        {
          path: 'status',
          children: [
            {
              path: '/',
              element: <Navigate to="404" replace />,
            },
            {
              path: '404',
              element: <Status404 />,
            },
            {
              path: '500',
              element: <Status500 />,
            },
            {
              path: 'maintenance',
              element: <StatusMaintenance />,
            },
            {
              path: 'coming-soon',
              element: <StatusComingSoon />,
            },
          ],
        },
        {
          path: '*',
          element: <Status404 />,
        },
      ],
    },
    {
      path: 'dashboards',
      element: <SidebarLayout />,
      children: [
        {
          path: '/',
          element: <Navigate to="/dashboards/home" replace />,
        },
        {
          path: 'home',
          element: <Home />,
        },
      ],
    },
    {
      path: 'management',
      element: <SidebarLayout />,
      children: [
        {
          path: '/',
          element: <Navigate to="/management/clients" replace />,
        },
        {
          path: 'clients',
          children: [
            {
              path: '/',
              element: <Clients />,
            },
            {
              path: 'new',
              element: <CreateClient />,
            },
            {
              path: 'view/:id',
              element: <ViewClient />,
            },
            {
              path: 'edit/:id',
              element: <UpdateClient />,
            },
          ],
        },
        {
          path: 'contracts',
          element: <Contracts />,
        },
      ],
    },
    admin
      ? {
          path: 'administrator',
          element: <SidebarLayout />,
          children: [
            {
              path: 'users',
              children: [
                {
                  path: '/',
                  element: <Users />,
                },
                {
                  path: 'new',
                  element: <CreateUser />,
                },
                {
                  path: 'edit/:id',
                  element: <UpdateUser />,
                },
              ],
            },
          ],
        }
      : {},
  ] as PartialRouteObject[];

export default routes;
